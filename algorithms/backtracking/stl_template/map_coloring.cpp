// February 2000/Solving Combinatorial Problems with STL and Backtracking
#include <assert.h>

#include <functional>
#include <vector>

#include "BackTrack.h"


enum State
   {ME, NH, VT, MA, CT, RI, NY, PA, NJ, DE, MD, DC, 
    VA, NC, WV, SC, GA, FL, AL, TN, KY, OH, IN, MI, 
    MS, LA, AR, MO, IL, WI, IA, MN, ND, SD, NE, KS, 
    OK, TX, NM, CO, WY, MT, ID, UT, AZ, NV, CA, OR, WA};

const int NumberStates = 49;
const int MaxNeighbors = 8;

enum Color {Blue, Yellow, Green, Red};

inline Color&amp; operator++ (Color&amp; c)
{
   c = Color (c + 1);
   return c;
}

inline State&amp; operator++ (State&amp; c)
{
   c = State (c + 1);
   return c;
}

typedef std::vector&lt;Color&gt; Map;
typedef Map::iterator MapIter;


// store neighbor's of each state.
// Neighbor [i][0] == # of neighbors  of state i
// Neighbor [i][j] == jth neighbor of state i
State Neighbor [NumberStates][MaxNeighbors+1]; 

inline Connect (State s1, State s2)
{
   int count = ++Neighbor [s1][0];
   Neighbor [s1][count] = s2;

   count = ++Neighbor [s2][0];
   Neighbor [s2][count] = s1;

   assert (Neighbor [s1][0] &lt;= MaxNeighbors);
   assert (Neighbor [s2][0] &lt;= MaxNeighbors);
}


void BuildMap ()
{
   for (int i = 0; i &lt; NumberStates; i++)
         Neighbor [i][0] = State(0);


   Connect (ME,NH);
   Connect (NH,VT); Connect (NH,MA);
   Connect (VT,MA); Connect (VT,NY);
   Connect (MA,NY); Connect (MA,CT); Connect (MA,RI);
   Connect (CT,RI); Connect (CT,NY);
   Connect (NY,NJ); Connect (NY,PA); Connect (NY,OH);
   Connect (PA,NJ); Connect (PA,DE); Connect (PA,MD); 
   Connect (PA,WV); Connect (PA,OH);

   // ... omitted to save space -- full source code available
   // on CUJ ftp site (see p. 3 for downloading instructions)

   Connect (UT,NV); Connect (UT,AZ);
   Connect (AZ,NV); Connect (AZ,CA);
   Connect (NV,OR); Connect (NV,CA);
   Connect (CA,OR);
   Connect (OR,WA);
}


struct ColorIsValid : 
   public std::binary_function&lt;MapIter, MapIter, bool&gt; 
{
   bool operator() (const MapIter&amp; begin, const MapIter&amp; end) 
   {
      State LastState = State (end-begin-1);
      Color LastColor = *(end-1);
      bool Valid = true;
      for (int i = 1; i &lt;= Neighbor [LastState][0]; i++) {
         State NeighborState = Neighbor [LastState][i];
         if (NeighborState &lt; LastState &amp;&amp;
             *(begin+NeighborState) == LastColor)
             return false;
      }
      return true;
   }
};



int main (int argc, char* argv [])
{
   Map tree (NumberStates);

   BackTrack &lt;Color, MapIter, ColorIsValid&gt; ColorMap (Blue, Red);
   BuildMap ();

   bool FirstTime = true;
   // find first 100 valid colorings of the U.S.
   for (int i = 0; i &lt; 100; i++)
      bool Valid = 
         ColorMap (tree.begin(), tree.end(), FirstTime);

   return 0;
}
