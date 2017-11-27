
# commands:

```
help <cmd>

load <file>
save <file> <var> (-ascii)

who : shows variables
whos : var in cur scope
size
ls
pwd
clear <var> : delete all var

matrix not zero-based ?
slices supported on matrix
```

## special matrices:
```
ones()
eye()
zeros()
randn(3) - normal distrib
rand(3)
```

## Ops on matrices:
```
A .* B - element wise mult
A .^ B - elem wise exp
A ./ B - elem wise div
log (mat) - elem wise log
exp (mat) - elem wise exp
abs(mat)  
sum(mat) - add all elem
prod(mat) - prod of all elem
floor(mat) - elem wise
ceil(mat)  - elem wise
max(mat)
flipup
inv  - inverse
pinv - pseudo inverse

A = magic(3) - magic square

plot(t, y1, '<color>') - horizontal is t; vertical axis is y1
hold on     - plot new fig on old ones
xlabel('time')
ylabel('value')
legend('','')
title('my plot')
print -d<png> <filename>  - to save plot to file
close - close the plot window

figure (1); plot(t, y1) - specifies first figure (if u want more than one displayed)

subplot(1,2,1) - subdivides plot into 1x2 grid and starts access to first elem
then subplot(1,2,2) followed by plot(t, y2)

axis([0.5 1 -1 1]) - change x-range and y-range of axis

clf - clear a figure

imagesc(mat) - plot mxn grid of colors corresp to values
imagesc(mat), colorbar, colormap gray;
```
