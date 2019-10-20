#pragma once

#include <memory>

namespace bintree {
    template <typename T>
    struct TNode: std::enable_shared_from_this<TNode<T>> { // added for shared_from_this() method
        using TNodePtr = std::shared_ptr<TNode<T>>;
        using TNodeConstPtr = std::shared_ptr<const TNode<T>>;
        using TNodePtrWeak = std::weak_ptr<TNode<T>>; // added for parent ptr
        
        bool hasLeft() const {
            return bool(left);
        }

        bool hasRight() const {
            return bool(right);
        }

        bool hasParent() const {
            return !parent.expired(); // changed check for weak_ptr
        }

        T& getValue() {
            return value;
        }

        const T& getValue() const {
            return value;
        }

        TNodePtr getLeft() {
            return left;
        }

        TNodeConstPtr getLeft() const {
            return left;
        }

        TNodePtr getRight() {
            return right;
        }

        TNodeConstPtr getRight() const {
            return right;
        }

        TNodePtr getParent() {
            return parent.lock(); // shared from weak
        }

        TNodeConstPtr getParent() const {
            return parent.lock(); // shared from weak
        }

        static TNodePtr createLeaf(T v) {
            // changed because make_shared needs public constructors
            return TNodePtr (new TNode(v));
        }
        
        // changed args because of every time creating new shared issue with new counter
        static TNodePtr fork(T v, TNodePtr left, TNodePtr right) {
            // changed because make_shared needs public constructors
            TNodePtr ptr(new TNode(v, left, right));
            setParent(ptr->getLeft(), ptr);
            setParent(ptr->getRight(), ptr);
            return ptr;
        }

        TNodePtr replaceLeft(TNodePtr l) {
            // changed because of every time creating new shared issue with new counter
            setParent(l, this->shared_from_this());       
            setParent(left, nullptr);
            std::swap(l, left);
            return l;
        }

        TNodePtr replaceRight(TNodePtr r) {
            // changed because of every time creating new shared issue with new counter
            setParent(r, this->shared_from_this());
            setParent(right, nullptr);
            std::swap(r, right);
            return r;
        }

        TNodePtr replaceRightWithLeaf(T v) {
            return replaceRight(createLeaf(v));
        }

        TNodePtr replaceLeftWithLeaf(T v) {
            return replaceLeft(createLeaf(v));
        }

        TNodePtr removeLeft() {
            return replaceLeft(nullptr);
        }
        TNodePtr removeRight() {
            return replaceRight(nullptr);
        }

    private:
        T value;
        TNodePtr left = nullptr;
        TNodePtr right = nullptr;
        TNodePtrWeak parent; // avoid issue when parent can't be removed (cycle)

        TNode(T v)
            : value(v)
        {
        }
        // changed args because of every time creating new shared issue with new counter
        TNode(T v, TNodePtr left, TNodePtr right)
            : value(v)
            , left(left)
            , right(right)
        {
        }

        static void setParent(TNodePtr node, TNodePtr parent) {
            if (node)
                if (!parent)
                    node->parent.reset();
                else
                    node->parent = parent;
            
        }
    };
}
