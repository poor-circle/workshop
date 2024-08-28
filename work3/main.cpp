import std;
import animal;
int main() {
    auto animals = create_animals();
    for (auto &animal : animals) {
        std::cout<<animal_say(*animal);
    }
    return 0;
}