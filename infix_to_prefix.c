void infixToPrefix(char* infix, char* prefix) {
    structStack*stack= (struct Stack*)malloc(sizeof(struct Stack));
    initStack(stack);
    int i, j;
    int len = strlen(infix);
    
    // 입력된 Infix 표현식을 역순으로 스캔
    for (i = len - 1, j = 0; i >= 0; i--) {
        // 피연산자는 그대로 출력
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
            prefix[j++] = infix[i];
        }
        // 오른쪽 괄호는 스택에 push
        else if (infix[i] == ')') {
            push(stack, infix[i]);
        }
        // 왼쪽 괄호는 스택에서 pop하여 출력
        else if (infix[i] == '(') {
            while (!isEmpty(stack) && top(stack) != ')') {
                prefix[j++] = pop(stack);
            }
            // 왼쪽 괄호 '('를 스택에서 제거
            if (!isEmpty(stack) && top(stack) == ')') {
                pop(stack);
            }
        }
        // 연산자 처리
        else {
            // 스택이 비어있거나, 스택의 top에 있는 연산자의 우선순위가 현재 연산자의 우선순위보다 작을 때까지 스택에서 pop하여 출력
            while (!isEmpty(stack) && getPriority(top(stack)) >= getPriority(infix[i])) {
                prefix[j++] = pop(stack);
            }
            // 현재 연산자를 스택에 push
            push(stack, infix[i]);
        }
    }
    // 스택에 남아있는 연산자들을 출력
    while (!isEmpty(stack)) {
        prefix[j++] = pop(stack);
    }
    prefix[j] = '\0';
    // 결과를 역순으로 뒤집어서 Prefix 표현식으로 완성
    strrev(prefix);
    free(stack);
}
