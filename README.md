# Binomial Distribution Visualiser
![image](https://user-images.githubusercontent.com/65414576/157391910-6fe68afd-8177-4030-9cd3-28b03a7e3824.png)

`X ~ B(n,p)` is drawn for any valid parameters `n`, `p`

# How to use # 
All the code required to run the program in `main.cpp`

Call function as :
```cpp
BinomialVisualiser(n, p);
```

For large values of `n`, you might have to scroll up/down a bit to view the distribution.
# Modifications #
Several parameters of the diagram can be changed but is not recommended because of different possible sizes of the terminal.

The default settings should work on all terminal screens which have been maximised.

Default settings :
```cpp
TotalBlocks = 10; //controls grid width
Subdivisions = 8; //controls grid width
NumberOfDP = 3; //for scale
```
## Changing the grid size ##
Increasing `TotalBlocks` and `Subdivisions` will increase the accuracy of the plotting while increasing the size of the diagram horizontally.

Obey the following rules :

- `TotalBlocks * Subdivisions < 100` (so that there is no "merging" of rows)
- `TotalBlocks > 5`
- `Subdivisions > 0`

## Modifying scale ##
`NumberOfDP` determines the number of decimal places in the numbers displayed on the scale.
As a general rule of thumb, ensure that `2 < NumberOfDP < 5` so that there is no "merging" of numbers. 
# Future work #
- [ ] Get rid of awkward scale (Choose only sensible scales which are multiples of 2, 5)
- [ ] Ensure that it works on an online compiler.
- [x] Do not hard code FilledBlock, EmptyBlock
- [ ] Color the graph
- [x] Deal with large values of n (Do not plot all values of x)
- [ ] output E(X), Var(X), mode

# Inspiration #
https://homepage.divms.uiowa.edu/~mbognar/applets/bin.html

https://shiny.rit.albany.edu/stat/binomial/
