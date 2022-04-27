 $$ \frac{G}{H} \int_{a}^{b} \cdot \Delta \nabla \sigma \Sigma \Pi {a}^{b} {b}_{a} \dot{v} \vec{v} \space \partial $$$$

A_{2\times2} =

\left[ {\begin{array}{cc}

a_{11} & a_{12} \\

a_{21} & a_{22} \\

\end{array} } \right]

$$

$$ \newcommand{\bbar}{\bar{\bar{} \@\xspace} $$

this is $ \frac{x}{y} $ latex 

**State Space** - puts stuff into matrices
- electromechanical circuit analysis
	- states describe how much energy is stored in each energy storage compnent
		- Knowing how and where the energy stored for every lets you solve for multiple inputs and multiple solutions
	

We've only looked at SISO (Single Input, Single Output) systems thusfar
- If we looked at speed and velocity, its SIMO (Single Input, Multiple output). MISO, MIMO
- MIMO (and other M systems) can be solved via superposition - Only for LTI 

**Steps to solve a circuit using state space**
1. Identify independent states - x
2. Write the state equation(s) 
$$  {\dot{x} = f(x,v)} $$
4. Combine into Matrix $$ \bar{\dot{x}} = \bar{\bar{A}}\bar{x} + \bar{\bar{B}}\bar{u}$$
4. Identify all outputs - y
5. Compute $$ y = g(x,v)$$
6. Combine $$ \bar{y} = \bar{\bar{C}}\bar{x} + \bar{\bar{D}}\bar{v} $$
7.  Solve MIMO
	7.1 - transfer function $$ \frac{\bar{y}}{\bar{u}}$$

$$ \bar{y} = \bar{\bar{E}}\bar{v} $$
$$ \bar{\bar{E}} = \bar{\bar{C}}\bar{\bar{\Phi}}\bar{\bar{B}} + \bar{\bar{D}} $$

$$ \Phi = f(\bar{\bar{A}}^{-1})$$ we'll come back to phi


The E matrix is just full of transfer functions between 

States 
- Capacitors - based on voltage
- Inductors - current

State Derivations
- i = C dv/dt 
$$ i = C\dot{v} $$
$$ \dot{v} = \frac{1}{C}i $$ - KCL
- v = L di/dt
$$ v = L\dot{i} $$
$$ \dot{i} = \frac{1}{L}v $$ - KVL

![[Pasted image 20220214105749.png]]

![[Pasted image 20220214110046.png]]

I = i1 + i2 -> dependent and therefor we only have 3 independent states. the currents cause the bottom two inductors to be related. If you try to invert a matrix with more states than there are independent ones, you won't be able to properly invert it in matlab. (If you have any dependent states, A will not be full rank)

![[Pasted image 20220214111904.png]]

$$ \bar{\dot{x}} = \bar{\bar{A}}\bar{x} + \bar{\bar{X}}\bar{v}$$
$$ v_1 \space v_2 \space i $$

$$ \begin{bmatrix} \dot{v_1} \\ \dot{v_2} \\ \dot{i} \end{bmatrix} = \left[ {\begin{array}{cc}

\space &  \space \\

\space & \space \\

\end{array} } \right]_{3\times3} \begin{bmatrix} {v_1} \\{v_2} \\ {i} \end{bmatrix} + \left[ {\begin{array}{cc}

\space &  \space \\

\space & \space \\

\end{array} } \right]_{3\times2}\begin{bmatrix} V \\ I  \end{bmatrix}$$

use KCL -> entering = leaving

n1: $$ C\dot{v}_1 + \frac{1}{R}v_1$$

$$ \dot{v_1} = \frac{-1}{RC}{v_1} + \frac{1}{C}I $$
can now fill part of matrix

$$ \begin{bmatrix} \dot{v_1} \\ \dot{v_2} \\ \dot{i} \end{bmatrix} = \left[ {\begin{array}{cc}

\frac{-1}{R_1}{C_1} & 0 & 0\\

\space &  \space&  \space \\
\space &  \space&  \space \\

\end{array} } \right]_{3\times3} \begin{bmatrix} {v_1} \\{v_2} \\ {i} \end{bmatrix} + \left[ {\begin{array}{cc}

0 & \frac{1}{C_1} \\

\space & \space \\

\end{array} } \right]_{3\times2}\begin{bmatrix} V \\ I  \end{bmatrix}$$

![[Pasted image 20220214112314.png]] - supernode 

n2: $$ I + C_2\dot{v_2} + \frac{1}{R_2}v_2 = i$$
$$ \dot{v_2} = \frac{-1}{R_2\cdot{C_2}}v_2 + \frac{1}{C_2}i - \frac{1}{C_2}I $$

$$ \begin{bmatrix} \dot{v_1} \\ \dot{v_2} \\ \dot{i} \end{bmatrix} = \left[ {\begin{array}{cc}

\frac{-1}{R_1}{C_1} & 0 & 0\\

0 &  \frac{-1}{R_2\cdot{C_2}}v_2 &  \frac{1}{C_2} \\
\space &  \space&  \space \\

\end{array} } \right]_{3\times3} \begin{bmatrix} {v_1} \\{v_2} \\ {i} \end{bmatrix} + \left[ {\begin{array}{cc}

0 & \frac{1}{C_1} \\

0 & \frac{-1}{C_2}\\

\end{array} } \right]_{3\times2}\begin{bmatrix} V \\ I  \end{bmatrix}$$

n4: $$ -V + v_2 + L\dot{i} = 0 $$
$$ \dot{i} = \frac{-1}{L}v_2 + \frac{1}{L}V $$

$$ \begin{bmatrix} \dot{v_1} \\ \dot{v_2} \\ \dot{i} \end{bmatrix} = \left[ {\begin{array}{cc}

\frac{-1}{R_1}{C_1} & 0 & 0\\

0 &  \frac{-1}{R_2\cdot{C_2}}v_2 &  \frac{1}{C_2} \\
0 &  \frac{-1}{L} &  0 \\

\end{array} } \right]_{3\times3} \begin{bmatrix} {v_1} \\{v_2} \\ {i} \end{bmatrix} + \left[ {\begin{array}{cc}

0 & \frac{1}{C_1} \\

0 & \frac{-1}{C_2}\\

\frac{1}{L} & 0 \\

\end{array} } \right]_{3\times2}\begin{bmatrix} V \\ I  \end{bmatrix}$$

Output equation:

$$ \bar{Y} = \bar{\bar{C}}\bar{x} + \bar{\bar{D}} \bar{v} $$

$$ \begin{bmatrix} v_{n1} \\ i_{R2} \end{bmatrix} = \left[ {\begin{array}{cc}

1 & -1 & 0\\

0 & \frac{1}{R_2} &  0 \\

\end{array} } \right]_{2\times3} \begin{bmatrix} {v_1} \\{v_2} \\ {i} \end{bmatrix} + \left[ {\begin{array}{cc}

1 & 0 \\

0 & 0\\


\end{array} } \right]_{2\times2}\begin{bmatrix} V \\ I  \end{bmatrix}$$

Just do it by inspection, assuming you know all the values already. The matrix equation with A and B is the general case you use to actually solve problems, this is just a way to write what your output should be. Vn1 and stuff can change, you can add more rows for other values you want. All just based on your different states.

$$ \bar{y}_{2\times{1}} = \bar{\bar{T}}_{2\times2}\bar{u}_{2\times1} $$
$$  \bar{\dot{x}} = \bar{\bar{A}}\bar{x} + \bar{\bar{X}}\bar{u} $$
$$ \bar{Y} = \bar{\bar{C}}\bar{x} + \bar{\bar{D}} \bar{u} $$
$$ s\bar{x} = \bar{\bar{A}}\bar{x} + \bar{\bar{B}}\bar{u} $$
$$ (s-\bar{\bar{A}})\bar{x} = \bar{\bar{B}}\bar{u} $$
this is not possible unless s is a scalar multiplied by the identity matrix.
$$ (sI-\bar{\bar{A}})\bar{x} = \bar{\bar{B}}\bar{u} $$
$$ \bar{x} = (sI-\bar{\bar{A}})^{-1}{\bar{\bar{B}}\bar{u}} = \bar{\bar{\Phi}} \bar{\bar{B}}\bar{u} $$ and therefore 

$$ \bar{y} = (\bar{\bar{C}}\bar{\bar{\Phi}}{\bar{\bar{B}}} + \bar{\bar{D}})\bar{u} $$

where 
$$ (\bar{\bar{C}}\bar{\bar{\Phi}}{\bar{\bar{B}}} + \bar{\bar{D}}) = \bar{\bar{T}} $$

$$ \ddot{x} $$
