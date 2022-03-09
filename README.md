# Binomial Distribution Visualiser
![image](https://user-images.githubusercontent.com/65414576/157201067-5c2ab688-e7a2-4ff1-8a6a-9d2fab77ae9d.png)

`X ~ B(n,p)` is drawn for any valid parameters `n`, `p`

# How to use # 
All the code required to run the program in `main.cpp`

Call function as :
```cpp
BinomialVisualiser(10,0.6);
```
## Modifications ##
The following parameters of the grid can be changed but is not recommended because of different possible sizes of your terminal.

Default settings :
```cpp
TotalBlocks = 10; //controls grid width
Subdivisions = 8; //controls grid width
NumberOfDP = 3; //for scale
```
## Changing the grid size ##

TotalBlocks * Subdivisions < 100
## Modifying scale ##

# Future work #
- [ ] Get rid of awkward scale (Choose only sensible scales which are multiples of 2, 5)
- [x] Do not hard code FilledBlock, EmptyBlock
- [ ] Color the graph
- [x] Deal with large values of n (Do not plot all values of x)
- [ ] output E(X), Var(X), mode

# Inspiration #
https://homepage.divms.uiowa.edu/~mbognar/applets/bin.html

https://shiny.rit.albany.edu/stat/binomial/
