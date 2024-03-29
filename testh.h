#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "dsexceptions.h"
#include <iostream>    // For NULL
#include <iomanip>	   // To set the width for the line numbers for words
using namespace std;

// BinarySearchTree class
//
// CONSTRUCTION: with ITEM_NOT_FOUND object used to signal failed finds
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class BinarySearchTree
{
 public:
 BinarySearchTree( ) :root( NULL )
    {
    }

 BinarySearchTree( const BinarySearchTree & rhs ) : root( NULL )
    {
      *this = rhs;
    }

  /**
   * Destructor for the tree
   */
  ~BinarySearchTree( )
    {
      makeEmpty( );
    }

  /**
   * Find the smallest item in the tree.
   * Throw UnderflowException if empty.
   */
  const Comparable & findMin( ) const
  {
    if( isEmpty( ) )
      throw UnderflowException( );
    return findMin( root )->element;
  }

  /**
   * Find the largest item in the tree.
   * Throw UnderflowException if empty.
   */
  const Comparable & findMax( ) const
  {
    if( isEmpty( ) )
      throw UnderflowException( );
    return findMax( root )->element;
  }

  /**
   * Returns true if x is found in the tree.
   */
  bool contains( const Comparable & x ) const
  {
    return contains( x, root );
  }

  /**
   * Test if the tree is logically empty.
   * Return true if empty, false otherwise.
   */
  bool isEmpty( ) const
  {
    return root == NULL;
  }

  /**
   * Print the tree contents in sorted order.
   */
  void printTree( ostream & out = cout ) const
  {
    if( isEmpty( ) )
      out << "Empty tree" << endl;
    else
      printTree( root, out );
  }

  /**
   * Make the tree logically empty.
   */
  void makeEmpty( )
  {
    makeEmpty( root );
  }

  /**
   * Insert x into the tree; duplicates are ignored.
   */
  void insert( const Comparable & x, int y )
  {
    insert( x, root, y);
  }

	void search ( const Comparable & x, ostream & out = cout )
	{
		search ( x, root, out );
	}

	void findHeight ( ostream & out = cout )
	{
		findHeight( root, out );
	}

  /**
   * Remove x from the tree. Nothing is done if x is not found.
   */
  void remove( const Comparable & x )
  {
    remove( x, root );
  }

  /**
   * Deep copy.
   */
  const BinarySearchTree & operator=( const BinarySearchTree & rhs )
    {
      if( this != &rhs )
	{
	  makeEmpty( );
	  root = clone( rhs.root );
	}
      return *this;
    }

 private:
      struct BinaryNode
      {
	Comparable element;
	BinaryNode *left;
	BinaryNode *right;
	// Added this for the vector
	vector<int> lineNumberList;
      BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt, vector<int> lnl )
      : element( theElement ), left( lt ), right( rt ), lineNumberList( lnl ) { }
      };


      BinaryNode *root;


      /**
       * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
      void insert( const Comparable & x, BinaryNode * & t, int l )
      {
	if( t == NULL ) {
	  t = new BinaryNode( x, NULL, NULL, vector<int>() );
	  t->lineNumberList.push_back(l);
	}
	else if( x < t->element )
	  insert( x, t->left, l );
	else if( t->element < x )
	  insert( x, t->right, l );
	else
	  t->lineNumberList.push_back(l);  // Duplicate; do nothing
      }

      /**
       * Internal method to remove from a subtree.
       * x is the item to remove.
       * t is the node that roots the subtree.
       * Set the new root of the subtree.
       */
      void remove( const Comparable & x, BinaryNode * & t )
      {
	if( t == NULL )
	  return;   // Item not found; do nothing
	if( x < t->element )
	  remove( x, t->left );
	else if( t->element < x )
	  remove( x, t->right );
	else if( t->left != NULL && t->right != NULL ) // Two children
	  {
	    t->element = findMin( t->right )->element;
	    remove( t->element, t->right );
	  }
	else
	  {
	    BinaryNode *oldNode = t;
	    t = ( t->left != NULL ) ? t->left : t->right;
	    delete oldNode;
	  }
      }

      /**
       * Internal method to find the smallest item in a subtree t.
       * Return node containing the smallest item.
       */
      BinaryNode * findMin( BinaryNode *t ) const
      {
	if( t == NULL )
	  return NULL;
	if( t->left == NULL )
	  return t;
	return findMin( t->left );
      }

      /**
       * Internal method to find the largest item in a subtree t.
       * Return node containing the largest item.
       */
      BinaryNode * findMax( BinaryNode *t ) const
      {
	if( t != NULL )
	  while( t->right != NULL )
	    t = t->right;
	return t;
      }


      /**
       * Internal method to test if an item is in a subtree.
       * x is item to search for.
       * t is the node that roots the subtree.
       */
      bool contains( const Comparable & x, BinaryNode *t ) const
      {
	if( t == NULL )
	  return false;
	else if( x < t->element )
	  return contains( x, t->left );
	else if( t->element < x )
	  return contains( x, t->right );
	else
	  return true;    // Match
      }
      /****** NONRECURSIVE VERSION*************************
    bool contains( const Comparable & x, BinaryNode *t ) const
    {
        while( t != NULL )
            if( x < t->element )
                t = t->left;
            else if( t->element < x )
                t = t->right;
            else
                return true;    // Match

        return false;   // No match
    }
      *****************************************************/

      /**
       * Internal method to make subtree empty.
       */
      void makeEmpty( BinaryNode * & t )
      {
	if( t != NULL )
	  {
	    makeEmpty( t->left );
	    makeEmpty( t->right );
	    delete t;
	  }
	t = NULL;
      }

      /**
       * Internal method to print a subtree rooted at t in sorted order.
       */
      void printTree( BinaryNode *t, ostream & out ) const
      {
	if( t != NULL )
	  {
	    printTree( t->left, out );
	    out << t->element << " ";
	    //print out the vector
		  out << right << setw(17-t->element.size());
		for (auto i = t->lineNumberList.begin(); i != t->lineNumberList.end()-1; i++)
		    out << *i << ", ";
		  out << t->lineNumberList.back() << endl;

      out << lineNumberList[1] <<  endl;
	    printTree( t->right, out );
	  }
      }
      
	void search ( const Comparable & x, BinaryNode * t, ostream & out = cout ) {
		if (t != NULL) {
			if (t->element == x)
			{
				for (auto i = t->lineNumberList.begin(); i != t->lineNumberList.end()-1; i++)
					out << *i << ", ";
				out << t->lineNumberList.back() << endl;
			}
			search(x, t->left, out);

			search(x, t->right, out);
		}
	}

	void findHeight ( BinaryNode * t, ostream & out = cout )
	{
		out << height(t);
	}

      /**
       * Internal method to clone subtree.
     */
      BinaryNode * clone( BinaryNode *t ) const
      {
	if( t == NULL )
	  return NULL;
	else
	  return new BinaryNode( t->element, clone( t->left ), clone( t->right ), t->lineNumberList);
      }

 public:

      static int height(BinaryNode* t) {
	// returns the height of the tree t
	if (t == NULL) return 0;
	else {
	  int p = height(t->left);
	  int q = height(t->right);
	  if (p < q)
	    return 1+q;
	  else return 1 + p;

	}
      }

      static int size(BinaryNode* t) {
	if (t == NULL) return 0;
	else
	  return 1 + size(t->left) + size(t->right);
      }

      BinaryNode* getRoot() {
	return root;
      }

};

#endif
