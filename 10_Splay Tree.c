/*

SPLAY TREE

PROBLEM WITH OTHERS:
    AVL- extr storage fo rhigh fields & periulous delete code
    RED-BLACK- Complex Coding
 
ADVANTAGES 
 blind adjusting version of AVL trees
 amortized time for all operations is O(log n)
 worst case time is O(n)
 Different idea: Trade a little balance for faster access of most
recently searched for/inserted items
 insert/find always rotates node to the root!


Splaying Cases
Node being accessed (n) is:
 Root
 Child of root
 Has both parent (p) and grandparent (g)
Zig-zig pattern: g -> p -> n is left-left or right-right
Zig-zag pattern: g -> p -> n is left-right or right-left

Why Splaying Helps
 If a node n on the access path is at depth d beforethe splay, it’s at about depth d/2 after the splay
     Exceptions are the root, the child of the root, andthe node splayed
 Overall, nodes which are below nodes on the accesspath tend to move closer to the root
 Splaying gets amortized O(log n) performance.
(Maybe not now, but soon, and for the rest of theoperations.)

Splay Operations: Find/Search
 Find/Search the node in normal BST manner
 Splay the node to the root

Splay Operations: Insert
 Ideas?
 Can we just do BST insert?

Digression: Splitting
 Split(T, x) creates two BSTs L and R:
 all elements of T are in either L or R (T = L R)
 all elements in L are  x
 all elements in R are  x
 L and R share no elements (L  R = )

Splitting in Splay Trees
How can we split?
 We have the splay operation.
 We can find x or the parent of where x should be.
 We can splay it to the root.
 Now, what’s true about the left subtree of the root?
 And the right?


void insert(Node *& root, Object x)
{
Node * left, * right;
split(root, left, right, x);
root = new Node(x, left, right);
}

Splay Tree Summary
Can be shown that any M consecutive operations starting from an empty tree take at most O(M log(N))
 All splay tree operations run in amortized O(log n) time
O(N) operations can occur, but splaying makes them infrequent
Implements most-recently used (MRU) logic
 Splay tree structure is self-tuning

Splaying can be done top-down; better because:
 only one pass
 no recursion or parent pointers necessary
There are alternatives to split/insert and join/delete
Splay trees are very effective search trees
 relatively simple: no extra fields required
 excellent locality properties:
frequently accessed keys are cheap to find (near top of tree)
infrequently accessed keys stay out of the way (near bottom of tree) 
*/