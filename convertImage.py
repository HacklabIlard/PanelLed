from PIL import Image

# Open the PNG image
img = Image.open("image.png")

# Get the dimensions of the image
width, height = img.size

# Create a 2-dimensional array to store the RGB values of each pixel
rgb_array = []

# Loop through each pixel in the image and get its RGB values
for y in range(height):
    row = []
    for x in range(width):
        r, g, b = img.getpixel((x, y))
        row.append((r, b, g))
    rgb_array.append(row)

for x in rgb_array:
    line = str(x)
    line = line.replace("[", "{")
    line = line.replace("]", "}")
    line = line.replace("(", "{")
    line = line.replace(")", "}")
    line+=","
    print(line)
