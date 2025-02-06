# 📌 FDF Project Documentation  

## 📜 Table of Contents  
1. 🚀 Moving the Map  
2. 🔍 Scaling the Map (Zooming)  
3. 🔄 Rotating the Map (3D Rotation)  
4. 🖼️ Isometric Projection  
5. 📌 MLX Library (MiniLibX)  
6. 🖼️ Bitmap (Image Basics)  
7. 🖥️ Resolution (Pixel Density)  
8. 📌 X-Window System  

---

## 🚀 Moving the Map  
1. **Find the Center:**  
   - Get the **smallest and biggest coordinates** of the map.  
   - Move the map so that the smallest coordinate is at **(0,0)**.  
   - Shift the map to the **center of the window** using:  
     Center = (Window Size / 2) - Min Coordinate  

2. **Move the Map with Keyboard:**  
   - Add an **offset** value to move the map **left, right, up, or down**.  

---

## 🔍 Scaling the Map (Zooming)  
1. **Find the Biggest Size of the Map:**  
   - Use:  
     max_size = map width × map height  
   - Scale the map so it fits inside the window.  

2. **Adjusting Height (Z-axis):**  
   - Scale the **Z-axis** based on the width of the map.  

---

## 🔄 Rotating the Map (3D Rotation)  
We use **math formulas** to rotate the map around the **X, Y, and Z axes**.

### X-Axis Rotation (Up/Down)  
x' = x  
y' = y × cos(angle) - z × sin(angle)  
z' = y × sin(angle) + z × cos(angle)  

### Y-Axis Rotation (Left/Right)  
x' = x × cos(angle) + z × sin(angle)  
y' = y  
z' = -x × sin(angle) + z × cos(angle)  

### Z-Axis Rotation (Spinning)  
x' = x × cos(angle) - y × sin(angle)  
y' = x × sin(angle) + y × cos(angle)  
z' = z  

---

## 🖼️ Isometric Projection  
- **Rotate 45° around the Z-axis** → Aligns X and Y axes equally.  
- **Rotate 54.7° around the X-axis** → Tilts the Z-axis downward.  

📌 **This makes the projection look isometric.** ✅  

---

## 📌 MLX Library (MiniLibX)  
**MiniLibX (MLX)** is a **simple graphics library** to draw on the screen **without needing deep knowledge** of X-Window or Cocoa.  

---

## 🖼️ Bitmap (Image Basics)  
A **bitmap** is a **grid of pixels**, where each pixel stores color information.

1. **Size:**  
   - Defined by **width × height** (number of pixels).  
2. **Color Depth:**  
   - Controls how much color data each pixel has.  
   - Example:  
     - **1-bit** → Black/White  
     - **8-bit** → Grayscale  
     - **24-bit** → Full RGB Colors  

---

## 🖥️ Resolution (Pixel Density)  
Resolution tells how many pixels are packed in an area.  
- Measured in **PPI (Pixels Per Inch) or DPI (Dots Per Inch)**.  
- **Higher resolution** → Clearer image.  
- **Lower resolution** → Pixelated image.  

---

## 📌 X-Window System (How Graphics Work in Linux)  
The **X-Window System** manages graphics in Linux. It works with:  

1. **X Server:**  
   - Controls the **display, keyboard, and mouse**.  
   - Runs on your **computer**.  
2. **X Clients:**  
   - Applications that **show windows** (like MLX or web browsers).  
   - Can run **locally** or **remotely over a network**.  
3. **X Protocol:**  
   - Allows **X Clients** to talk to the **X Server**.  
   - Makes it possible to **run programs remotely** but display them locally.  

---  
