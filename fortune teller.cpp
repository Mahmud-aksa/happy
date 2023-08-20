#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_FORTUNES 7
#define NUM_HOROSCOPES 12

const char *fortunes[NUM_FORTUNES] = {
    "You will have a prosperous year ahead!",
    "Expect exciting new opportunities in your future.",
    "Be prepared for challenges that will make you stronger.",
    "Your creativity will lead to great success.",
    "Take time to reflect on your past to shape your future.",
    "A journey you take this year will bring you joy.",
    "Your hard work will pay off in unexpected ways."
};

const char *horoscopes[NUM_HOROSCOPES] = {
    "Aries: Embrace new beginnings and take charge of your life.",
    "Taurus: Focus on stability and your financial well-being.",
    "Gemini: Communication will be your key to success this year.",
    "Cancer: Embrace change and let go of the past.",
    "Leo: Your charisma will open doors to new opportunities.",
    "Virgo: Pay attention to the details; success lies in the small things.",
    "Libra: Seek balance in all aspects of your life for harmony.",
    "Scorpio: Your determination will lead to transformation.",
    "Sagittarius: Adventure awaits you; take risks and explore.",
    "Capricorn: Hard work will pave the way to your goals.",
    "Aquarius: Embrace your uniqueness and seek intellectual growth.",
    "Pisces: Trust your intuition and go with the flow."
};

int getValidInput(const char *prompt, int min, int max) {
    int input;
    do {
        printf("%s (%d-%d): ", prompt, min, max);
        scanf("%d", &input);
        if (input < min || input > max) {
            printf("Invalid input. Please enter a value between %d and %d.\n", min, max);
        }
    } while (input < min || input > max);
    return input;
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Birthdate Fortune Teller and Horoscope!\n");

    int birthMonth = getValidInput("Enter your birth month", 1, 12);
    int birthDay = getValidInput("Enter your birth day", 1, 31);

    int fortuneIndex = (birthDay + birthMonth) % NUM_FORTUNES;
    int horoscopeIndex = birthMonth - 1;

    printf("\nCalculating your fortune and horoscope...\n");
    printf("====================================\n");
    printf("Birth Month: %d\n", birthMonth);
    printf("Birth Day: %d\n", birthDay);
    printf("Your Fortune: %s\n", fortunes[fortuneIndex]);
    printf("Your Horoscope: %s\n", horoscopes[horoscopeIndex]);
    printf("====================================\n");

    return 0;
}
