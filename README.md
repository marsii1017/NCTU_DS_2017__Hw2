# NCTU_DS_2017__Hw2
It is homework 2 of data strcture in NCTU
# 1.Pseudo Code:
<pre>
 See the pseudo code in the report.pdf above.
</pre>

# 2.Approach work:
<pre>

1. Specially, I Construct a struct which is named “Node”, set list<Node> chain and an iterator points to list<Node>
 
<img src="https://github.com/marsii1017/NCTU_DS_2017__Hw2/blob/master/pic_1.PNG" width="500"> 

2. Utilize the way of ifstream, we can get the chain.name.
3. Fill out the chain.name by loop.
4. We read the vocabulary row by row. Because each of word does not interact.
5. Determine if the clock is clockwise, and push back the char to chain.text. We also observe where the iterator is. If it is chain.end(), then we must move it to chain.begin().

<img src="https://github.com/marsii1017/NCTU_DS_2017__Hw2/blob/master/pic_2.PNG" width="500"> 

6.If I read the end of word, we erase the gamer which receives the word. We also observe the end of word is vowel, and determine if change the direction of the list.
7. The direction is anti-clockwise, and we practice like step 5.
8. Like the step 6.

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
  
