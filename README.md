<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>FDF Project Documentation</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
            max-width: 800px;
            margin: 20px auto;
            padding: 20px;
            background-color: #f4f4f4;
        }
        h1, h2 {
            color: #333;
        }
        code {
            background-color: #eee;
            padding: 5px;
            display: block;
            white-space: pre-wrap;
        }
        .note {
            font-style: italic;
            color: #666;
        }
    </style>
</head>
<body>

    <h1>FDF Project Documentation</h1>

    <h2>Moving the Map</h2>
    <p><strong>1. Find the Center:</strong></p>
    <ul>
        <li>Get the <strong>minimum and maximum coordinates</strong> of the map.</li>
        <li>Shift the map to the origin by subtracting the <strong>minimum coordinate</strong>.</li>
        <li>Move the map to the <strong>center of the window</strong> using:
            <code>Center = (Window Width/Height) / 2 - Min Coordinate</code>
        </li>
    </ul>

    <p><strong>2. Moving with Keyboard Hooks:</strong></p>
    <ul>
        <li>Add an <strong>offset</strong> to move the map around the window.</li>
    </ul>

    <h2>Scaling the Map (Zooming)</h2>
    <p><strong>1. Find the Maximum Projection:</strong></p>
    <ul>
        <li>Calculate: <code>max_projection = max width × max height</code></li>
        <li>Scale the map so it fits inside the window.</li>
    </ul>

    <p><strong>2. Scaling the Height (Z-axis):</strong></p>
    <ul>
        <li>Adjust the Z-axis based on the map’s width for better visualization.</li>
    </ul>

    <h2>Rotating the Map (3D Rotation)</h2>
    <p>To rotate the 3D map, we use mathematical formulas for <strong>X, Y, and Z rotations</strong>.</p>

    <h3>X-Axis Rotation (Up/Down Tilt)</h3>
    <code>
        x' = x;
        y' = y * cos(angle) - z * sin(angle);
        z' = y * sin(angle) + z * cos(angle);
    </code>

    <h3>Y-Axis Rotation (Left/Right Turn)</h3>
    <code>
        x' = x * cos(angle) + z * sin(angle);
        y' = y;
        z' = -x * sin(angle) + z * cos(angle);
    </code>

    <h3>Z-Axis Rotation (Spinning Around Center)</h3>
    <code>
        x' = x * cos(angle) - y * sin(angle);
        y' = x * sin(angle) + y * cos(angle);
        z' = z;
    </code>

    <h2>Isometric Projection</h2>
    <ul>
        <li><strong>Rotate 45° around the Z-axis:</strong> Aligns the X and Y axes symmetrically.</li>
        <li><strong>Rotate 54.7° around the X-axis:</strong> Tilts the Z-axis downward for a 3D effect.</li>
    </ul>

    <p class="note">After these rotations, the projection becomes isometric.</p>

    <h2>MLX Library (MiniLibX)</h2>
    <p><strong>MiniLibX (MLX)</strong> is a small graphics library for drawing on a screen without deep knowledge of X-Window or Cocoa.</p>

    <h2>Bitmap (Image Basics)</h2>
    <p>A <strong>bitmap</strong> is a grid of pixels where each pixel contains color information.</p>
    <ul>
        <li><strong>Size:</strong> Defined by <code>width × height</code>.</li>
        <li><strong>Color Depth:</strong> Determines the amount of color information per pixel (e.g., 1-bit for black/white, 24-bit for full RGB).</li>
    </ul>

    <h2>Resolution (Pixel Density)</h2>
    <p>Resolution measures how densely the pixels are packed, typically in <strong>PPI (Pixels Per Inch) or DPI (Dots Per Inch)</strong>.</p>

    <h2>X-Window System (How Graphics Work in Linux)</h2>
    <ul>
        <li><strong>X Server:</strong> Controls the display, keyboard, and mouse.</li>
        <li><strong>X Clients:</strong> Programs that request display services (e.g., web browsers, MLX).</li>
        <li><strong>X Protocol:</strong> Enables communication between X Clients and the X Server.</li>
    </ul>

</body>
</html>
