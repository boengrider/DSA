
void funA();
void funB(int);

int main() {

    funA();

}


void funA() {
    int x;
    funB(x);
}

void funB(int i) {
    int y = i;
}