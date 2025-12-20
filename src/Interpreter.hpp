#ifndef LFI3A_INTERPRETER_HPP
#define LFI3A_INTERPRETER_HPP

#include <unordered_map>
#include <memory>
#include <vector>
#include "AST.hpp"

class Interpreter {
public:
    void run(const std::vector<ASTNodePtr>& nodes);
    
private:
    std::unordered_map<std::string, std::string> vars;
    std::unordered_map<std::string, ASTNodePtr> functions;
    std::string returnValue;
    bool hasReturned = false;
    
    std::string evaluate(const ASTNodePtr& node);
    void execute(const ASTNodePtr& node);
    bool isTruthy(const std::string& value);
    std::string toNumber(const std::string& value);
    std::string toString(const std::string& value);
};

#endif
