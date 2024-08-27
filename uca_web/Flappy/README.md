# Flappy Bird Game

Welcome to the Flappy Bird Game! This is a simple browser-based game where you control a bird trying to avoid obstacles. The game keeps track of your score, and the highest score is saved using `localStorage`, so you can always try to beat your previous best!

## Table of Contents

- [Features](#features)
- [How to Play](#how-to-play)
- [Installation](#installation)
- [Usage](#usage)
- [Code Overview](#code-overview)
- [Contributing](#contributing)

## Features

- **Simple Controls**: Use the `Enter` key to start the game and the `Arrow Up` key or the `Space` bar to control the bird.
- **Score Tracking**: The game tracks your score in real-time as you avoid obstacles.
- **High Score**: Your highest score is saved locally on your browser, so you can try to beat it every time you play.
- **Responsive Design**: The game scales to fit your browser window, providing an optimal gaming experience.

## How to Play

1. **Start the Game**: Press the `Enter` key to start the game.
2. **Control the Bird**: Use the `Arrow Up` key or the `Space` bar to make the bird fly upwards. Release the key to let gravity pull the bird down.
3. **Avoid Obstacles**: Navigate through the pipes without hitting them. The game ends when the bird collides with an obstacle or the ground.
4. **Track Your Score**: Your score increases each time you successfully pass through a pair of pipes. Try to beat your highest score!

## Installation

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/coolguy-codin-Rydham/FlappyUCA.git
   cd flappy-bird-game
   ```

2. **Open the Game**:
   - Simply open the `index.html` file in your preferred web browser.

## Usage

Once you've opened the game in your browser:

- Press `Enter` to start the game.
- Use the `Arrow Up` key or the `Space` bar to control the bird.
- Try to avoid obstacles and get the highest score possible!

## Code Overview

### HTML

The main structure of the game is defined in the `index.html` file. It includes the following key elements:

- A `div` for the game background.
- An `img` element representing the bird.
- `div`s for displaying the current score and the highest score.
- The `script.js` file, which contains the game logic.

### JavaScript

The game logic is implemented in the `script.js` file:

- **Game Initialization**: The game initializes with the bird hidden and waits for the user to press `Enter` to start.
- **Main Game Loop**: The game loop handles bird movement, pipe generation, collision detection, and score tracking.
- **High Score Tracking**: The highest score is saved in `localStorage` and displayed each time the game starts.

### CSS

The game's styles are managed through a CSS file located in the `assets` directory. It handles the positioning and styling of game elements.

### Assets

- **Images**: Bird images and a favicon are stored in the `images` directory.
- **Sounds**: The game includes sound effects for scoring and when the game ends, located in the `sounds effect` directory.

## Contributing

If you'd like to contribute to the project, feel free to fork the repository and submit a pull request. Contributions are welcome!