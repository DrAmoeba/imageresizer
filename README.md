# Imageresize - Resize and change format of any Image


Example, resize jpeg to 320x240:
./imageresize -i test.jpg -o test2.jpg -f jpeg -x 320 -y 240 -q 100

./imageresize --help
Usage:
  imageresize [OPTION...]  - Imageresizer

Help Options:
  -h, --help       Show help options

Application Options:
  -i, --input      Input Filename
  -o, --output     Output Filename
  -f, --format     Output Format: png,jpeg,bmp,ico,...
  -x, --sizex      Resize to X Pixels
  -y, --sizey      Resize to Y Pixels
  -q, --qual       Output Quality 1-100
