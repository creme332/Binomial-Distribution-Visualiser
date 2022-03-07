# Binomial Distribution Visualiser
![image](https://user-images.githubusercontent.com/65414576/156934633-601ec42f-bec1-431a-97cb-f38d8c7b29d0.png)

`X ~ B(n,p)` is drawn for any valid parameters `n`, `p`

# Future work #
- [ ] adaptive scale
- [ ] colors
- [ ] output E(X), Var(X), mode
- [ ] Optimise : Use symmetry when p=0.5 and calculate only first half of probabilities

# Inspiration #
https://homepage.divms.uiowa.edu/~mbognar/applets/bin.html

https://shiny.rit.albany.edu/stat/binomial/

# About #
The shape of a binomial distribution is symmetrical when p=0.5 or when n is large.
# Function call # 

```cpp
BinomialVisualiser(10,0.6)
```
