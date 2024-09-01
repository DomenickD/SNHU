import random
import gym
import numpy as np
from collections import deque
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
from tensorflow.keras.optimizers import Adam
import tensorflow as tf

# If score_logger is not available, you can remove it or implement a simple logging mechanism.
from scores.score_logger import ScoreLogger

ENV_NAME = "CartPole-v1"

GAMMA = 0.95
LEARNING_RATE = 0.001

MEMORY_SIZE = 1000000
BATCH_SIZE = 20

EXPLORATION_MAX = 1.0
EXPLORATION_MIN = 0.01
EXPLORATION_DECAY = 0.995


class DQNSolver:

    def __init__(self, observation_space, action_space):
        self.exploration_rate = EXPLORATION_MAX

        self.action_space = action_space
        self.memory = deque(maxlen=MEMORY_SIZE)

        self.model = Sequential()
        self.model.add(Dense(24, input_shape=(observation_space,), activation="relu"))
        self.model.add(Dense(24, activation="relu"))
        self.model.add(Dense(self.action_space, activation="linear"))
        self.model.compile(loss="mse", optimizer=Adam(learning_rate=LEARNING_RATE))

    def remember(self, state, action, reward, next_state, done):
        self.memory.append((state, action, reward, next_state, done))

    def act(self, state):
        state = np.array(state)  # Ensure state is a NumPy array
        if np.random.rand() < self.exploration_rate:
            return random.randrange(self.action_space)
        state = np.reshape(state, [1, -1])  # Reshape state to match model input
        q_values = self.model.predict(state, verbose=0)
        return np.argmax(q_values[0])

    def experience_replay(self):
        if len(self.memory) < BATCH_SIZE:
            return
        batch = random.sample(self.memory, BATCH_SIZE)
        for state, action, reward, state_next, terminal in batch:
            state = np.array(state)  # Ensure state is a NumPy array
            state_next = np.array(state_next)  # Ensure next state is a NumPy array
            state = np.reshape(state, [1, -1])
            state_next = np.reshape(state_next, [1, -1])
            q_update = reward
            if not terminal:
                q_update = reward + GAMMA * np.amax(
                    self.model.predict(state_next, verbose=0)[0]
                )
            q_values = self.model.predict(state, verbose=0)
            q_values[0][action] = q_update
            self.model.fit(state, q_values, verbose=0)
        self.exploration_rate *= EXPLORATION_DECAY
        self.exploration_rate = max(EXPLORATION_MIN, self.exploration_rate)


def cartpole():
    env = gym.make(ENV_NAME)
    observation_space = env.observation_space.shape[0]
    action_space = env.action_space.n
    dqn_solver = DQNSolver(observation_space, action_space)
    run = 0
    while True:
        run += 1
        state, _ = env.reset()  # Unpack the tuple and ignore the dictionary
        state = np.array(state)  # Convert only the relevant part to a NumPy array
        state = np.reshape(state, [1, -1])  # Correctly reshape the initial state
        step = 0
        while True:
            step += 1
            action = dqn_solver.act(state)
            results = env.step(action)
            state_next = results[0]  # Extract the state_next from the results
            reward = results[1]
            terminal = results[2]
            # Handle any additional returned values (like info) as necessary
            reward = reward if not terminal else -reward
            state_next = np.array(state_next)  # Ensure next state is a NumPy array
            state_next = np.reshape(
                state_next, [1, -1]
            )  # Correctly reshape the next state
            dqn_solver.remember(state, action, reward, state_next, terminal)
            state = state_next
            if terminal:
                print(
                    f"Run: {run}, exploration: {dqn_solver.exploration_rate:.4f}, score: {step}"
                )
                break
            dqn_solver.experience_replay()


if __name__ == "__main__":
    cartpole()
