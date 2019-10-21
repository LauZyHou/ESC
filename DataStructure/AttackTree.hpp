#include "iostream"
#include <list>
#include <string>

enum nodetype {BEFORE, AFTER, AND, OR, XOR, SEQUENCE};   ///< all types of AttackNode.

/// \brief the attack protocal bound to attack nodes or attack trees.
class Attack {
private:
    bool enable;
    AttackNode* originNode;
    bool leaf;
    bool final;
    bool root;
};

/// \brief the node for attack tree.
class AttackNode {
private:
    Attack* resultingAttack;
    std::list<Attack*> inputAttacks;
    std::list<int> inputValues;

protected:
    nodetype type;
};

/// \brief attack tree protocal.
class AttackTree {
private:
    std::list<AttackNode*> nodes;
    std::list<Attack*> attacks;

public:
    AttackNode* faultyNode;
    std::string errorOfFaultyNode;
};

/// \brief the node about temporal relationship.
class TimeNode : public AttackNode {
private:
    int time;
};

class BeforeNode : public TimeNode {
public:
    BeforeNode() {
        this->type = BEFORE;
    }
};

class AfterNode : public TimeNode {
public:
    AfterNode() {
        this->type = AFTER;
    }
};

/// \brief the node about logical operations.
class BoolNode : public AttackNode {

};

class ANDNode : public BoolNode {
public:
    ANDNode() {
        this->type = AND;
    }
};

class ORNode : public BoolNode {
public:
    ORNode() {
        this->type = OR;
    }
};

class XORNode : public BoolNode {
public:
    XORNode() {
        this->type = XOR;
    }
};

/// \brief the node about sequence.
class SequenceNode : public AttackNode {
public:
    SequenceNode() {
        this->type = SEQUENCE;
    }
};