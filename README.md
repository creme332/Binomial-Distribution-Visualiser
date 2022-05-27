# 📊Binomial Distribution Visualiser

![image](https://user-images.githubusercontent.com/65414576/157391910-6fe68afd-8177-4030-9cd3-28b03a7e3824.png)

```
					 X ~ B (10, 0.5)

	0.000     0.032     0.065     0.098     0.131     0.164     0.196     0.229     

x < 1	 |....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|

x = 1	 |@@..|....|....|....|....|....|....|....|....|....|....|....|....|....|....|

x = 2	 |@@@@|@@@@|@@@.|....|....|....|....|....|....|....|....|....|....|....|....|

x = 3	 |@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|....|....|....|....|....|....|....|....|

x = 4	 |@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@..|....|....|

x = 5	 |@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|

x = 6	 |@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@..|....|....|

x = 7	 |@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|@@@@|....|....|....|....|....|....|....|....|

x = 8	 |@@@@|@@@@|@@@.|....|....|....|....|....|....|....|....|....|....|....|....|

x = 9	 |@@..|....|....|....|....|....|....|....|....|....|....|....|....|....|....|

x > 9	 |....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|


Mean = 5
Mode = 5
Variance = 2.5

x	 P(X=x)
0	0.000977
1	0.009766
2	0.043945
3	0.117188
4	0.205078
5	0.246094
6	0.205078
7	0.117188
8	0.043945
9	0.009766
10	0.000977
```

![image](https://user-images.githubusercontent.com/65414576/157603181-c5ec6308-b09c-436b-923f-7b81f64f6ac7.png)
<sup>*Here n = 1000 and p = 0.13* 


$X\sim B(n,p)$ is drawn for any valid parameters $n$, $p$. Other information such as the mean, mode, variance, and proabability distribution table can also be output.
  
# 🚀 Setup # 
All the code required to run the program in `main.cpp`. It is recommended to put your terminal in full screen. If you are using an [online compiler](https://www.onlinegdb.com/online_c++_compiler) use the code from `OnlineCompilerVersion` file.

Call function as :
```cpp
BinomialVisualiser(n, p);
```

For large values of $n$, you might have to scroll up/down the terminal to view the full distribution.
# 🔨 Modifications #
Several parameters of the diagram can be changed but is not recommended because of different possible sizes of the terminal.

The default settings should work on all terminals which are in full screen.

Default settings :
```cpp
TotalBlocks = 10; //controls grid width
Subdivisions = 8; //controls grid width
NumberOfDP = 3; //controls the number of decimal places for numbers on scale
```
## Changing the grid size ##
Increasing `TotalBlocks` and `Subdivisions` will increase the accuracy of the plotting but also increases the size of the diagram horizontally.

As a rule of thumb to avoid invalid diagrams, try to satisfy the following conditions  :

- `TotalBlocks * Subdivisions < 100` (so that there is no "merging" of rows)
- `TotalBlocks > 5`
- `Subdivisions > 0`

## Changing scale ##
`NumberOfDP` determines the number of decimal places in the numbers displayed on the scale. 
Condition that must always be satisfied : `Subdivisions > NumberOfDP`

# 🌠Inspiration #
https://homepage.divms.uiowa.edu/~mbognar/applets/bin.html

https://shiny.rit.albany.edu/stat/binomial/
