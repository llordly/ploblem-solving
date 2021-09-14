# **Homework#2**

## 1. Chapter 1 summarize
### 

### **result**
```
machine accuracy of float with machar(): 1.19209e-07
machine accuracy of double with machar_double(): 2.22045e-16
```

## 2. Solve Problem
### 

  
  ### 3.6
  code in 3-6.cpp
  
```
  true value: 6.737949e-03
  first method: 6.745540e-03
  second method: 6.737948e-03

  relative error of first method: -1.126618e-03
  relative error of second method: 2.158695e-07

  case of terms are 100
  first method: 6.737947e-03
  second method: 6.737947e-03

  relative error of first method: 2.969621e-07
  relative error of second method: 2.969620e-07

```
  relative error is lower when terms are added 
  
  ### 3.7
  #### 3 digit chopping
```
- 6x = 3.462 = 0.3462 * 10 -> 0.346 * 10 = 3.46
-  x^2 = 0.332929 -> 0.332
- 3x^2 = 0.996
- 1 - 3x^2 = 0.004
- 3.46/0.004^2 = 216250
```

  #### 4 digit chopping
```
- 6x = 3.462 = 0.3462 * 10 -> 3.462
- x^2 = 0.332929 -> 0.3329
- 3x^2 = 0.9987
- 1 - 3x^2 = 0.0013
- 3.462 / 0.0013^2 = 2048520.710059171597633
```
  
  ### 4.2
code in 4-2.cpp
- `es = (0.5 * 10^(2-n))% = 0.005` is two significant figures 
- `et` is relative error and `ea`is Approximate relative error
- program will terminate when `ea < es`
#### result
```
estimated value: 4.516886e-01, relative error: 9.66227% approximate relative error: 1.21391
estimated value: 5.017962e-01, relative error: -0.35924% approximate relative error: 0.0998564
estimated value: 4.999646e-01, relative error: 0.00708693% approximate relative error: 0.00366353
program terminate with 3 step
```
  ### 4.5
  - true value = f(3) = 554
  - zero order
    - p0(x) = f(x0) -> f(1) = -62
    - (554 - (-62)) / 554 => 111.19133574%
- first order
   - p1(x) = f(x0) + f'(x0)(x-x0) = 78
   - (554 - 78) / 554 => 85.9205776%
- second order
  - p2(x) = f(x0) + f'(x0)(x - x0) + f''(x0)(x-x0)^2/2! = 354
  - (554 - 354) / 554 => 36.101083%
- third order
  - p3(x) =  f(x0) + f'(x0)(x - x0) + f''(x0)(x-x0)^2/2! + f'''(x0)(x-x0)^3/3! = 554
  - (554 - 554) / 554 = 0%
  
  ### 4.12
  
$$
\Delta v(\tilde{c},\tilde{m}) = \left | \frac{\partial v}{\partial c}\right |\Delta \tilde{c} +  \left | \frac{\partial v}{\partial m}\right |\Delta \tilde{m} = \left | \frac{g\tilde{m}}{\tilde{c}^2}(e^{-\frac{\tilde{c}}{\tilde{m}}t}-1)+\frac{gt}{\tilde{c}}e^{-\frac{\tilde{c}}{\tilde{m}}t}\right |\Delta \tilde{c} + \left | \frac{g}{\tilde{c}}-e^{-\frac{\tilde{c}}{\tilde{m}}t}(\frac{g}{\tilde{c}}+\frac{gt}{\tilde{m}}\right |\Delta \tilde{m} = \left | -1.3811 \right |\cdot 1.5 + \left | 0.347 \right |\cdot 2 = 2.776
$$

$$
v \cong \frac{9.81\cdot 50}{12.5}(1 - e^{-\frac{12.5}{50}6}) = 30.484 \pm 2.776
$$
