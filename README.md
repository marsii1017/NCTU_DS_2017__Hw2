# NCTU_DS_2017__Hw2
It is homework 2 of data strcture in NCTU
# 1.Pseudo Code:
<pre>
 See the pseudo code in the report.pdf above.
<pre>

# 2. Approach work:
<pre>
1. Specially, I Construct a struct which is named “Node”, set list<Node> chain and an iterator points to list<Node>

</pre>
# 3. Time Complexity:
<pre>
N: the number of people play the game
M: the max length of the vocabulary.
We must read the (N-1) rows vocabulary row by row. we
Distribute every char of the vocabularies to each gamer, and we also know the max size of the word is M. 
So we can ensure time complexity of this program is equally less than (N-1)*M. 
This means the time complexity for big O is O(N*M).
</pre>
# The challenge in this work
<Pre>
  Because many marginal conditions in this work, so I spent a big part of time arranging the order of these conditions. 
  In addition, we have to aware of changing the iterator and ensure it is legal for the alteration, 
  or might cause segment default error.
  
</pre>
  
