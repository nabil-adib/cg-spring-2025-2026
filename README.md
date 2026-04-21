# cg-spring-2025-2026
CSC 4118: Computer Graphics

## 🚗 OpenGL Animated Cityscape

A 2D animated city environment built using **OpenGL (GLUT) in C++**, showcasing a dynamic urban scene with moving vehicles, environmental elements, and interactive day-night transitions.

### 🎯 Features

* 🌤️ **Day/Night Mode Toggle**

  * Press `D` for Day
  * Press `N` for Night
  * Dynamic sky color, sun/moon switch, and illuminated windows at night

* ☁️ **Animated Clouds**

  * Multiple cloud layers moving at different speeds for depth effect

* 🚘 **Moving Vehicles**

  * Vertical and horizontal car animations
  * Rotating wheels for realism
  * Reverse-moving car with continuous looping

* 🌆 **City Infrastructure**

  * Roads, footpaths, zebra crossing layout
  * Traffic signal system
  * Street lighting elements

* 🏢 **Buildings & Shops**

  * Multiple structures with windows, doors, and color variations
  * Night mode window lighting simulation

* 🌳 **Natural Elements**

  * Trees with layered leaves
  * Park area with soil, waterbody, and bushes

* 💡 **Extra Elements**

  * Decorative energy portal
  * Border outline using `GL_LINE_LOOP`
  * Scene depth through layering and positioning

---

### 🛠️ Technologies Used

* **C++**
* **OpenGL**
* **GLUT**

---

### ⚙️ How It Works

* Animation is handled using `glutTimerFunc`
* Object movement is controlled via translation variables
* Rotation (wheel motion) uses transformation matrices
* Scene rendering is structured using modular functions (`idXXXX`)

---

### ▶️ How to Run

1. Install OpenGL and GLUT libraries
2. Compile using a C++ compiler (e.g., MinGW)

```bash
g++ main.cpp -lglut -lGL -lGLU -o cityscape
./cityscape
```

---

### 📌 Controls

| Key | Action     |
| --- | ---------- |
| D   | Day Mode   |
| N   | Night Mode |

---

### 🚀 Future Improvements

* Add zebra crossing implementation
* Tree leaf texture variation (multi-color shading)
* Park bench and shop banners
* Improved lighting effects
* More realistic vehicle physics and interactions

---

### 💭 Notes

This project focuses on fundamental **computer graphics concepts**:

* Transformations (translation, rotation)
* Scene composition
* Animation loops
* Color and lighting simulation (basic)


