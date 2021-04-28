#Set the output to a png file
set terminal png size 400,400
#The file we'll write to
set output 'data.png'
# The graphic title
#set title 'Rata duplicatelor'
set ylabel 'Rata duplicatelor [%/Total pachete]'
set xlabel 'Numar esantioane'
set grid
unset key

#plot the graphic
plot "data.txt" with lines lc "violet" lw 2
pause -1

