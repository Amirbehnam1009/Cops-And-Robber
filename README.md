# 👮♂️🚨 Cops and Robber Simulation 🦹♂️💨

<img src="https://github.com/user-attachments/assets/cbcede00-d228-400e-9bf4-d9b31b4c75a7" width="500" height = "500" alt="Lucid_Origin_A_dynamic_cyberpunkstyle_8x8_grid_with_glowing_ne_0" />


## 📖 About
This project is a simulation of a pursuit game between cops and robbers, developed as the midterm project for the Fundamental Programming course under the supervision of Professor Bahador Bakhshi in Fall 2019. The simulation models the dynamic interactions between robbers and police officers in a grid-based environment, incorporating elements of random movement, detection, and coordinated pursuit.

## ✨ Features
- 🎛️ **Customizable Environment**: Users can define the dimensions of the playground (grid) and the number of police stations and officers.
- 🎮 **Dynamic Gameplay**: The robber moves randomly, while police officers either move randomly or strategically toward the robber based on their awareness of the robber's location.
- 🔍 **Detection Mechanism**: Police officers can detect the robber if they are within a 5x5 square centered on the officer's position. Upon detection, officers from the same station are notified of the robber's location.
- 👀 **Real-Time Visualization**: The simulation displays the grid at each time step, showing the positions of the robber and police officers, with a brief pause between steps for clarity.
- � **Game Conclusion**: The game ends when the robber is either surrounded by officers or apprehended by a cop.

## 🛠️ How It Works
### 🏁 Initialization:
1. 📏 The user specifies the grid dimensions (n x m).
2. 🚓 The user sets the number of police stations and the number of officers per station.
3. 🎲 The initial positions of the robber and police officers are randomly assigned, ensuring no two entities occupy the same cell.

### 🔄 Simulation Loop:
1. ⏱️ At each time step `t`, the robber and police officers decide their next move.
2. 🏃♂️ The robber moves randomly to an adjacent cell or stays in place.
3. 👮 Police officers move randomly if unaware of the robber's location. If aware, they move toward the robber using Manhattan distance for path calculation.
4. 🔦 Police officers detect the robber if the robber is within their 5x5 detection range. Upon detection, officers from the same station are informed of the robber's location.
5. 🕵️♂️ The robber's location is lost if it moves out of the detection range of all officers from a station.

### 🏁 Termination:
- 🚨 The simulation stops when the robber is caught (occupies the same cell as a police officer) or is surrounded.
- 📊 The total number of moves made by the robber and the cumulative moves by all police officers are displayed at the end.

## 💻 Technical Details
- 🗺️ **Grid Representation**: The environment is modeled as a 2D matrix, with each cell representing a possible position for the robber or police officers.
- 🚶 **Movement Logic**:
  - 🦹♂️ **Robber**: Moves randomly to one of the 8 adjacent cells or stays in place.
  - 👮♂️ **Police Officers**: Use Manhattan distance to determine the shortest path toward the robber when aware of its location.
- 📡 **Detection Range**: Officers detect the robber if the robber is within a 5x5 square centered on the officer's position.
- 👁️ **Visualization**: The grid is printed to the console at each time step, with a delay (`sleep`) to allow the user to follow the simulation. The console is cleared between steps for clarity.

## 🔮 Optional Features
- 🧠 **Robber Awareness**: The robber can detect nearby police officers and attempt to evade them.
- 🧊 **3D Environment**: Extend the simulation to a 3D grid for added complexity.
- 👥 **Multiple Robbers**: Allow the user to specify multiple robbers, with the simulation continuing until all robbers are caught.

## 📂 Repository Structure
- 💾 **Source Code**: Contains the implementation of the simulation in C/C++.
- 📝 **Documentation**: Includes the project description (PDF) and this README file.
- 🧪 **Examples**: Sample inputs and outputs to demonstrate the simulation.

## 🚀 Usage
1. Clone the repository:
   ```bash
   git clone https://github.com/Amirbehnam1009/Cops-And-Robber.git
