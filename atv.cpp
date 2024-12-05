#include <stdio.h>

struct Guess {
    char *value;
    Guess *prev;

    Guess(char *_value) {
        value = _value;
        prev = NULL;
    }
};

struct Stack {
    Guess *top;

    Stack() {
        top = NULL;
    }

    bool is_empty() {
        return top == NULL;
    }

    void push(char value[7]) {
        Guess *newGuess = new Guess(value);

        if (is_empty()) {
            top = newGuess;
            return;
        }

        newGuess->prev = top;
        top = newGuess;
    }

    void pop() {
        if (is_empty()) return;

        Guess *toDel = top;
        top = top->prev;
        delete(toDel);
    }

    char* peek() {
        return top->value;
    }
};

bool compare(char *last_guess, char *guess) {
    bool result = true;

    for (int i = 0, j = 6; i < 7, j >= 0; i++, j--) {
        if (last_guess[i] != guess[j]) {
            result = false;
            break;
        }
    }

    return result;
}

int main() {
    Stack stack;
    int count = 0, guesses;

    scanf("%d%*c", &guesses);

    while (guesses--) {
        char guess[7];
        // TODO: Está lendo cada letra como uma entrada, tem que ler a linha inteira como uma única entrada
        scanf("%[^\n]%*c", guess);

        if (!stack.is_empty() && compare(stack.peek(), guess)) {
            stack.pop();
            count++;
            continue;
        }

        stack.push(guess);
    }

    printf("%d\n", count);

    return 0;
}
