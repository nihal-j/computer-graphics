#Tidier Drawings of Trees
The objective of this project was to implement:
<b>E. M. Reingold and J. S. Tilford. 1981. Tidier Drawings of Trees. IEEE Trans. Softw. Eng. 7, 2 (March 1981), 223–228. </b>

The algorithm talks about an optimal tree drawing algorithm that takes into account four important aesthetics including symmetry of subtrees. The algoritm produces pleasing tree outputs. On a screen of $1920 \times 1080$, a depth of tree $20$ was achieved for a randomly spaced tree. However, only a depth of $7$ was achieved for complete binary trees.

OpenGL (with C++) was used to render the trees after the output was obtained from the algorithm described above.

<hr>

### Some outputs

<div style="text-align:center"><img src = img/2020-02-24_11-56-00_d_5/img2.jpg></img></div>

### <i>Bigger trees</i>
<div style="text-align:center"><img src=img/2020-02-24_12-03-03_d_20/img14.jpg></img></div>

<hr>

## Analysis of code
The execution time here is the time taken to:
   1. Generate the tree using generator
   2. Run the algorithm described in paper
   3. Get lines and circles for edges and nodes

Depth of tree | Number of nodes | Execution time
--- | --- | ---
*Still* | `renders` | **nicely**
1 | 2 | 3