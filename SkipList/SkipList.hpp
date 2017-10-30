#include <cstdlib>
//=============================================================================
//== NodeSkipList =============================================================
//=============================================================================

template <class Value, class Key, int numLevels>
void NodeSkipList<Value,Key,numLevels>::clear(void)
{
	for (int i = 0; i < numLevels; ++i)
	{
		m_nextjump[i] = 0;
	}
	m_levelHighest = -1;
}

template <class Value, class Key, int numLevels>
NodeSkipList<Value, Key, numLevels>::NodeSkipList(void)
{
	clear();
}

template <class Value, class Key, int numLevels>
NodeSkipList<Value, Key, numLevels>::NodeSkipList(Key key)
{
	clear();

	m_key = key;
}

template <class Value, class Key, int numLevels>
NodeSkipList<Value, Key, numLevels>::NodeSkipList(Key key, Value value)
{
	clear();

	m_key = key;
	m_value = value;
}
//=============================================================================
//== End of: NodeSkipList =====================================================
//=============================================================================

//=============================================================================
//== SkipList =================================================================
//=============================================================================
template <class Value, class Key, int numLevels>
SkipList<Value, Key, numLevels>::SkipList(double probability)
{
	m_probability = probability;
	for (int i = 0; i < numLevels; ++i)
	{
		// Lets use m_pPreHead as a final sentinel element
		m_pPreHead->m_nextjump[i] = m_pPreHead;
	}
	m_pPreHead->m_levelHighest = numLevels-1;
}

// Put your code here

template<class Value, class Key, int numLevels>
inline void SkipList<Value, Key, numLevels>::insert(Value value, Key key)
{
    srand(time(NULL));
    int rnd=rand()%0+1;
    TypeNode* ins_node=new TypeNode(key,value);

    while (rnd<m_probability&&ins_node->m_levelHighest<numLevels)
    {
        ins_node->m_levelHighest++;
    }

    TypeNode* nodeIter=this->m_pPreHead;
    for (int i=nodeIter->m_levelHighest;i>=-1;i--)
    {
        while ((nodeIter = i == -1 ? nodeIter->m_next : nodeIter->m_nextjump[i]) != this->m_pPreHead && nodeIter->m_key < key)
        {
             nodeIter= i == -1 ? nodeIter->m_next : nodeIter->m_nextjump[i];
        }
        i<=ins_node->m_levelHighest?(ins_node= i==-1?ins_node->m_next:ins_node->m_nextjump[i])=(nodeIter = i == -1 ? nodeIter->m_next : nodeIter->m_nextjump[i]),
                (nodeIter = i == -1 ? nodeIter->m_next : nodeIter->m_nextjump[i])=ins_node: false;
    }
}

template<class Value, class Key, int numLevels>
inline void SkipList<Value, Key, numLevels>::remove(TypeNode * node)
{
    TypeNode* nodeIter = this->m_pPreHead;

    while (nodeIter->m_next != this->m_pPreHead || nodeIter->m_next != node)
    {
        nodeIter = nodeIter->m_next;
    }
    if (nodeIter->m_next == this->getPreHead())
        throw std::invalid_argument("Wrong node in list");

    TypeNode* temp = nodeIter->m_next;
    for (int i = nodeIter->m_next->m_levelHighest; i >= 0; --i)
    {
        TypeNode* tmp = this->m_pPreHead;

        while (tmp->m_nextjump[i] != node)
        {
            tmp = tmp->m_nextjump[i];
        }
        tmp->m_nextjump[i] = tmp->m_nextjump[i]->m_nextjump[i];
    }
    nodeIter->m_next = nodeIter->m_next->m_next;
    delete temp;
}
template<class Value,class Key,int numLevels>
typename SkipList<Value,Key,numLevels>::TypeNode* SkipList<Value,Key,numLevels>::findLastLessThan(Key key) const {
    TypeNode *node = this->m_pPreHead;

    for (int i = numLevels - 1; i >= -1; i--) {

        TypeNode *nodenext;

        while ((nodenext = i == -1 ? node->m_next : node->m_nextjump[i]) != this->m_pPreHead && nodenext->m_key < key) {
            node = nodenext;
        }
    }

    return node;
}
template<class Value,class  Key,int numLevels>
typename SkipList<Value,Key,numLevels>::TypeNode* SkipList<Value,Key,numLevels>::findFirst(Key key) const
{
    TypeNode* node=findLastLessThan(key);
    if (node->m_next->m_key==key)
    {
        return  node->m_next;
}
}
//=============================================================================
//== End of: SkipList =========================================================
//=============================================================================
