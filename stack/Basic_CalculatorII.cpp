class Solution {
public:
stack<char> op; stack<int> dig;
unordered_map<char,int> m;

void trigger(){ // reverse the stack
    stack<char> t;
    while(!op.empty()){
        t.push(op.top());
        op.pop();
    }
    op = t;
    stack<int> tm;
    while(!dig.empty()){
        tm.push(dig.top());
        dig.pop();
    }
    dig = tm;
}

bool isDigit(char c){
    return (c >= '0' && c <= '9');
}

void scan(string exp){
    for(int i = 0; i < exp.size(); i++){
        if(exp[i] == ' ') continue;
        switch (exp[i]) {
          case '+':
          case '-':
          case '*':
          case '/':
              op.push(exp[i]);
              break;
          default:
              int val = 0;
              for(; i < exp.size(); i++){
                  if(!isDigit(exp[i]) || exp[i] == ' '){
                      i--;
                      break;
                  } else {
                      val *= 10;
                      val += exp[i] - '0';
                  }
              }
              dig.push(val);
        }
    }
}


int perform(int a, char o, int b){
    switch (o) {
      case '*': return a * b;
      case '/': return a / b;
      case '+': return a + b;
      case '-': return a - b;
    }
    return 0;
}

void eval(){ // operator with equal precedence are evaluated left to right
    int a = dig.top(); dig.pop();
    int o = op.top(); op.pop();
    if(op.empty() || m[o] >= m[op.top()]){
        int b = dig.top(); dig.pop();
        dig.push(perform(a, o, b));
    } else {
        eval();
        dig.push(a);
        op.push(o);
    }
}
    int calculate(string s) {
        scan(s);
        if(dig.size() == 0) return 0;
        if(op.size() == 0) return dig.top();
        m['*'] = 4;
        m['/'] = 4;
        m['+'] = 2;
        m['-'] = 2;
        trigger();
        while(dig.size() > 1){
            eval();
        }
        return dig.top();
    }
};
