import pygame
import sys
from board import Board
from game import Game, columns_dictionary, rows_dictionary

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GRAY = (200, 200, 200)
BLUE = (100, 150, 255)
RED = (255, 100, 100)
GREEN = (100, 255, 100)
YELLOW = (255, 255, 100)


class PygameBattleshipUI:
    def __init__(self):
        pygame.init()
        self.screen_width = 1200
        self.screen_height = 800
        self.screen = pygame.display.set_mode((self.screen_width, self.screen_height))
        pygame.display.set_caption("Battleship Game")

        # Setup game boards
        self.computer_board_representation = Board()
        self.user_board_representation = Board()
        self.user_board = Board()
        self.computer_board = Board()
        self.game = Game(self.user_board, self.computer_board,
                         self.user_board_representation, self.computer_board_representation)

        # Font
        self.font = pygame.font.Font(None, 36)

        # Game state
        self.game_state = 'ship_placement'
        self.current_ship = None
        self.ship_alignment = 'v'

        # Ship placement order
        self.ships_to_place = [
            ('Big Ship (4 squares)', 'B'),
            ('Medium Ship (3 squares)', 'M'),
            ('Small Ship (2 squares)', 'S')
        ]
        self.current_ship_index = 0

        # Track user shots
        self.user_shots = []

    def draw_grid(self, board, x_offset, y_offset, is_computer=False):
        cell_size = 50
        for row in range(8):
            for col in range(8):
                rect = pygame.Rect(
                    x_offset + col * cell_size,
                    y_offset + row * cell_size,
                    cell_size,
                    cell_size
                )
                pygame.draw.rect(self.screen, WHITE, rect, 1)

                # Show hits/misses/ships
                cell_value = board._data[row][col]
                color = None

                if is_computer:
                    # If cell was shot by the user
                    if (row, col) in self.user_shots:
                        if cell_value in ['B', 'M', 'S']:  # Hit a ship
                            color = RED
                        elif cell_value == ' ':  # Miss
                            color = GRAY
                        # Explicitly handle hit ships
                        elif cell_value in ['HB', 'HM', 'HS']:
                            color = RED
                        elif cell_value == 'X':
                            color = RED
                        elif cell_value == 'O':
                            color = GRAY

                else:  # User's board
                    if cell_value == 'O':  # Miss
                        color = GRAY
                    elif cell_value in ['X', 'HB', 'HM', 'HS']:  # Hits
                        color = RED
                    elif cell_value in ['B', 'M', 'S']:  # Ships on player board
                        color = GREEN

                if color:
                    inner_rect = pygame.Rect(
                        x_offset + col * cell_size + 2,
                        y_offset + row * cell_size + 2,
                        cell_size - 4,
                        cell_size - 4
                    )
                    pygame.draw.rect(self.screen, color, inner_rect)

                    # Add text to show hit or miss on computer board
                    if is_computer and (row, col) in self.user_shots:
                        font = pygame.font.Font(None, 24)
                        text_color = WHITE if color == RED else BLACK
                        text = font.render('X' if color == RED else 'O', True, text_color)
                        text_rect = text.get_rect(center=inner_rect.center)
                        self.screen.blit(text, text_rect)

        # Draw column and row labels
        for i, label in enumerate(['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']):
            col_text = self.font.render(label, True, WHITE)
            self.screen.blit(col_text, (x_offset + i * cell_size + 20, y_offset - 30))

        for i in range(1, 9):
            row_text = self.font.render(str(i), True, WHITE)
            self.screen.blit(row_text, (x_offset - 30, y_offset + (i - 1) * cell_size + 15))

    def place_ship(self, ship, row, col):
        result = self.user_board.place_ship(ship, row, col, self.ship_alignment)
        if result is True:
            self.current_ship_index += 1
            if self.current_ship_index >= len(self.ships_to_place):
                # Finish ship placement, place computer ships
                self.game.place_computer_ship(self.computer_board)
                self.game_state = 'playing'
        return result

    def handle_mouse_click(self, pos):
        cell_size = 50

        # User board placement logic
        if self.game_state == 'ship_placement':
            x_offset, y_offset = 50, 200
            col = (pos[0] - x_offset) // cell_size
            row = (pos[1] - y_offset) // cell_size

            if 0 <= row < 8 and 0 <= col < 8:
                ship_type = self.ships_to_place[self.current_ship_index][1]
                result = self.place_ship(ship_type, row, col)
                if result is not True:
                    print(result)  # Show error message

        # Computer board shooting logic
        elif self.game_state == 'playing':
            x_offset, y_offset = 650, 200
            col = (pos[0] - x_offset) // cell_size
            row = (pos[1] - y_offset) // cell_size

            if 0 <= row < 8 and 0 <= col < 8:
                # Check if this cell has already been shot
                if (row, col) not in self.user_shots:
                    state = self.game.player_shot(row, col, self.computer_board)
                    print(f"Player shot result: {state}")

                    if state != "You already shot here":
                        # Record the user's shot
                        self.user_shots.append((row, col))

                        # Computer's turn
                        computer_state = self.game.computer_move()
                        print(f"Computer shot result: {computer_state}")

                # Check win condition
                win_state = self.game.is_win()
                if win_state:
                    print(win_state)
                    self.game_state = 'game_over'

    def run(self):
        clock = pygame.time.Clock()

        while True:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    sys.exit()

                if event.type == pygame.KEYDOWN:
                    if self.game_state == 'ship_placement':
                        if event.key == pygame.K_v:
                            self.ship_alignment = 'v'
                        elif event.key == pygame.K_h:
                            self.ship_alignment = 'h'

                if event.type == pygame.MOUSEBUTTONDOWN:
                    self.handle_mouse_click(event.pos)

            # Clear screen
            self.screen.fill(BLACK)

            # Render game title
            title = self.font.render("Battleship Game", True, WHITE)
            self.screen.blit(title, (self.screen_width // 2 - 100, 50))

            # Ship placement instructions
            if self.game_state == 'ship_placement':
                ship_text = self.font.render(
                    f"Place {self.ships_to_place[self.current_ship_index][0]} " +
                    f"(Alignment: {'Vertical' if self.ship_alignment == 'v' else 'Horizontal'})",
                    True, WHITE
                )
                instructions = self.font.render(
                    "Press 'V' for Vertical, 'H' for Horizontal",
                    True, WHITE
                )
                self.screen.blit(ship_text, (50, 100))
                self.screen.blit(instructions, (50, 150))

            # Draw boards
            self.draw_grid(self.user_board, 50, 200)

            if self.game_state != 'ship_placement':
                self.draw_grid(self.computer_board, 650, 200, is_computer=True)

            # Display game state messages for game over
            if self.game_state == 'game_over':
                game_over_text = self.font.render(
                    self.game.is_win(),
                    True,
                    WHITE
                )
                self.screen.blit(game_over_text, (self.screen_width // 2 - 100, self.screen_height - 100))

            pygame.display.flip()
            clock.tick(30)


# Run the game
if __name__ == "__main__":
    game_ui = PygameBattleshipUI()
    game_ui.run()