////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief     Реализация классов красно-черного дерева
/// \author    Sergey Shershakov
/// \version   0.1.0
/// \date      01.05.2017
///            This is a part of the course "Algorithms and Data Structures" 
///            provided by  the School of Software Engineering of the Faculty 
///            of Computer Science at the Higher School of Economics.
///
/// "Реализация" (шаблонов) методов, описанных в файле rbtree.h
///
////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>        // std::invalid_argument


namespace xi {


//==============================================================================
// class RBTree::node
//==============================================================================

template <typename Element, typename Compar >
RBTree<Element, Compar>::Node::~Node()
{
    if (_left)
        delete _left;
    if (_right)
        delete _right;
}



template <typename Element, typename Compar>
typename RBTree<Element, Compar>::Node* RBTree<Element, Compar>::Node::setLeft(Node* lf)
{
    // предупреждаем повторное присвоение
    if (_left == lf)
        return nullptr;

    // если новый левый — действительный элемент
    if (lf)
    {
        // если у него был родитель
        if (lf->_parent)
        {
            // ищем у родителя, кем был этот элемент, и вместо него ставим бублик
            if (lf->_parent->_left == lf)
                lf->_parent->_left = nullptr;
            else                                    // доп. не проверяем, что он был правым, иначе нарушение целостности
                lf->_parent->_right = nullptr;      
        }

        // задаем нового родителя
        lf->_parent = this;
    }

    // если у текущего уже был один левый — отменяем его родительскую связь и вернем его
    Node* prevLeft = _left;
    _left = lf;

    if (prevLeft)
        prevLeft->_parent = nullptr;

    return prevLeft;
}


template <typename Element, typename Compar>
typename RBTree<Element, Compar>::Node* RBTree<Element, Compar>::Node::setRight(Node* rg)
{
    // предупреждаем повторное присвоение
    if (_right == rg)
        return nullptr;

    // если новый правый — действительный элемент
    if (rg)
    {
        // если у него был родитель
        if (rg->_parent)
        {
            // ищем у родителя, кем был этот элемент, и вместо него ставим бублик
            if (rg->_parent->_left == rg)
                rg->_parent->_left = nullptr;
            else                                    // доп. не проверяем, что он был правым, иначе нарушение целостности
                rg->_parent->_right = nullptr;
        }

        // задаем нового родителя
        rg->_parent = this;
    }

    // если у текущего уже был один левый — отменяем его родительскую связь и вернем его
    Node* prevRight = _right;
    _right = rg;

    if (prevRight)
        prevRight->_parent = nullptr;

    return prevRight;
}


//==============================================================================
// class RBTree
//==============================================================================

template <typename Element, typename Compar >
RBTree<Element, Compar>::RBTree()
{
    _root = nullptr;
    _dumper = nullptr;
}

template <typename Element, typename Compar >
RBTree<Element, Compar>::~RBTree()
{
    // грохаем пока что всех через корень
    if (_root)
        delete _root;
}


template <typename Element, typename Compar >
void RBTree<Element, Compar>::deleteNode(Node* nd)
{
    // если переданный узел не существует, просто ничего не делаем, т.к. в вызывающем проверок нет
    if (nd == nullptr)
        return;

    // потомков убьет в деструкторе
    delete nd;
}


template <typename Element, typename Compar >
void RBTree<Element, Compar>::insert(const Element& key)
{
    // этот метод можно оставить студентам целиком
    Node* newNode = insertNewBstEl(key);

    // отладочное событие
    if (_dumper)
        _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_BST_INS, this, newNode);

    rebalance(newNode);

    // отладочное событие
    if (_dumper)
        _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_INSERT, this, newNode);

}




template <typename Element, typename Compar>
const typename RBTree<Element, Compar>::Node* RBTree<Element, Compar>::find(const Element& key)
{
	Node* node = _root;
	while (node != nullptr) {
		if (key == node->_key) {
			return node;
		}
		key < node->_key ? node = node->_left : node = node->_right;
	}
	return nullptr;
}

template <typename Element, typename Compar >
typename RBTree<Element, Compar>::Node* 
        RBTree<Element, Compar>::insertNewBstEl(const Element& key)
{
	Node* node = _root;
	Node* temp = nullptr;
	while (node != nullptr) {
		if (key == node->_key) {
			std::logic_error("Key has already added!");
		}
		else
		{
			temp = node;
			key < node->_key ? node = node->_left : node = node->_right;

		}

	}

	Node* newnode = new Node(key);
	if (temp == nullptr) {
		_root= newnode;
	}
	else
	{
		newnode->_parent = temp;
		newnode->_color = RED;
		key < temp->_key ? temp->_left = newnode : temp->_right = newnode;
	}
	return newnode;
}


template <typename Element, typename Compar >
typename RBTree<Element, Compar>::Node* 
    RBTree<Element, Compar>::rebalanceDUG(Node* nd)
{
	Node* batya = nd->_parent;
	Node* grandbatya = batya->_parent;
	Node* uncle;
	grandbatya->_left == batya ? uncle = grandbatya->_right : uncle = grandbatya->_left;
    
	if (grandbatya->_right == uncle) {
		if (uncle&&uncle->_color == RED) {
			batya->_color = BLACK;
			uncle->_color = BLACK;
			grandbatya->_color = RED;
            
            nd = grandbatya;
            
			return grandbatya;
		}
		else {
			if (nd == batya->_right) {
                nd = (Node*)nd->getParent();
				rotLeft(nd);
			}
            
			batya->_color = BLACK;
			grandbatya->_color = RED;
			rotRight(grandbatya);
		}
	}
	else {
		if (uncle&&uncle->_color == RED) {
			batya->_color = BLACK;
			uncle->_color = BLACK;
			grandbatya->_color = RED;
            
            nd = grandbatya;
            
			return grandbatya;
		}
		else {
			if (nd == batya->_left) {
                nd = (Node*)nd->getParent();
                rotRight(nd);
			}
			nd->_parent->_color = BLACK;
			nd->_parent->_parent->_color = RED;
			rotLeft(nd->_parent->_parent);
		}
	}

    if (_dumper)
            _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_RECOLOR1, this, nd);


    if (_dumper)
        _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_RECOLOR3D, this, nd);


    if (_dumper)
        _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_RECOLOR3G, this, nd);

    return nd;
}


template <typename Element, typename Compar >
void RBTree<Element, Compar>::rebalance(Node* nd)
{

    // пока папа — цвета пионерского галстука, действуем
    while (nd->_parent&&nd->_parent->_color==RED)
    {
		nd = rebalanceDUG(nd);
    } 
	_root->_color = BLACK;

}



template <typename Element, typename Compar>
void RBTree<Element, Compar>::rotLeft(typename RBTree<Element, Compar>::Node* nd)
{
    // правый потомок, который станет после левого поворота "выше"
    Node* y = nd->_right;
    
    if (!y)
        throw std::invalid_argument("Can't rotate left since the right child is nil");
	nd->_right = y->_left;

	if (y->_left != nullptr) {
		y->_left->_parent = nd;
	}
	y->_parent = nd->_parent;
	if (nd->_parent == nullptr) {
		_root = y;
	}
	else if (nd == nd->_parent->_left) {
		nd->_parent->_left = y;
	}
	else {
		nd->_parent->_right = y;
	}
	y->_left = nd;
	nd->_parent = y;

    if (_dumper)
        _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_LROT, this, nd);
}



template <typename Element, typename Compar>
void RBTree<Element, Compar>::rotRight(typename RBTree<Element, Compar>::Node* nd)
{
	Node* y = nd->_left;

	if (!y)
		throw std::invalid_argument("Can't rotate left since the right child is nil");

	nd->_left = y->_right;
	if (y->_right != nullptr) {
		y->_right->_parent = nd;
	}
	y->_parent = nd->_parent;
	if (nd->_parent == nullptr) {
		_root = y;
	}
	else if (nd == nd->_parent->_right) {
		nd->_parent->_right = y;
	}
	else {
		nd->_parent->_left = y;
	}
	y->_right = nd;
	nd->_parent = y;
    
    if (_dumper)
        _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_RROT, this, nd);
}


} // namespace xi

