## MLX:

               is a tiny graphics library which allows you to do the most basic things for rendering something in screens without any knowledge of X-Window and Cocoa.

## Bitmap:

               is a grid of pixels, where each pixel contains color information. It is defined by two main parameters: 

1. Number of pixels **(width × heigh).**
2. Color depth (amount of information per pixel, e.g., 1-bit for black/white, 8-bit grayscale, or 24-bit RGB).

## Resolution:

               refers to how densely the pixels are packed when displayed or printed, measured in pixels per inch (PPI) or dots per inch (DPI). Higher resolution means smaller pixels and finer detail.

# X-Window:

**In the X Window System:**

1. the X Server: is the component that controls the display, keyboard, mouse, and other input/output devices. It runs on the machine where the graphical output is displayed (e.g., your local computer).
2. The X Clients are applications that request services from the X Server to display windows or process user inputs. These clients can run on the same machine as the server or on a remote machine over a network. 
3. The X Server communicates with X Clients using the X Protocol , enabling network transparency. This means you can run an application (X Client) on a remote server, and its graphical interface will appear on your local machine (where the X Server is running).
