// February 2000 Solving Combinatorial Problems with STL and Backtracking
#ifndef BackTrack_h
#define BackTrack_h

template &lt;class T, class I, class V&gt;
class BackTrack {
public:

   // precondition: first &lt;= last
   BackTrack(const T&amp;  first, const T&amp;  last);


   // Finds the next solution to the problem. Repeated calls 
   // will find all solutions to a problem if multiple solutions 
   // exist.
   // Returns true if a solution was found.
   //
   // Set first to true to get the first solution.
   //
   bool operator() (const I&amp; begin, I end, bool&amp; first);


private:
   // Finds the next valid sibling of the leaf (end-1). 
   // Returns true is if a valid sibling was found.
   bool FindValidSibling (const I&amp; begin, const I&amp; end);


   // Backtracks through the decision tree until it finds a node
   // that hasn't been visited. Returns true if an unvisited 
   // node was found.
   bool VisitNewNode (const I&amp; begin, I&amp; end);

   void CreateLeftLeaf (I&amp; end);

   T left_child;
   T right_child;

   V IsValid;
};

template &lt;class T, class I, class V&gt;
BackTrack&lt;T,I,V&gt;::BackTrack(const T&amp; first, const T&amp; last) 
   : left_child (first), right_child (last)
{
}

template &lt;class T, class I, class V&gt;
bool BackTrack&lt;T,I,V&gt;::VisitNewNode(const I&amp; begin, I&amp; end)
{
   // ALGORITHM:
   //
   // If the current node is the rightmost child we must 
   // backtrack one level because there are no more children at 
   // this level. So we back up until we find a non-rightmost 
   // child, then generate the child to the right. If we back 
   // up to the top without finding an unvisted child, then all 
   // nodes have been generated.

   // Back up as long as the node is the rightmost child of 
   // its parent.
   while (end-begin &gt; 0 &amp;&amp; *(end-1) == right_child)
      --end;

   I back = end-1;
   if (end-begin &gt; 0 &amp;&amp; *back != right_child) {
      ++(*back);
      return true;
   } else
      return false;
}

template &lt;class T, class I, class V&gt; 
bool BackTrack&lt;T,I,V&gt;::FindValidSibling
(const I&amp; begin, const I&amp; end)
{
   // Note that on entry to this routine the leaf has not yet 
   // been used or tested for validity, so the leaf is 
   // considered a "sibling" of itself.

   I back = end-1;
   while (true) {
      if (IsValid (begin, end))
         return true;
      else if (*back != right_child)
         ++(*back);
      else
         return false;
   }
}

template &lt;class T, class I, class V&gt;
inline void BackTrack&lt;T,I,V&gt;::CreateLeftLeaf (I&amp; end)
{
   *(end++) = left_child;
}

template &lt;class T, class I, class V&gt; 
bool BackTrack&lt;T,I,V&gt;::operator () 
(const I&amp; begin, I end, bool&amp; first)
{
   const int size = end - begin;

   // If first time, need to create a root.
   // Otherwise need to visit new node since vector
   // contains the last solution.
   if (first) {
      first = false;
      end = begin;
      CreateLeftLeaf (end);
   } else if (!VisitNewNode (begin, end))
      return false;

   while (true) {
      if (FindValidSibling (begin, end)) {
         if (end - begin &lt; size)
            CreateLeftLeaf (end);
         else
            return true;

      } else if (!VisitNewNode (begin, end))
         return false; // the tree has been exhausted, 
                       // so no solution exists.
   }
}
