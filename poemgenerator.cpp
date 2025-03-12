C++ Code

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <ctime>
#include <map>
#include <fstream>
#include <set>
#include <sstream>

using namespace std;

class PoemGenerator {
private:
    string theme;
    vector<string> wordBank;
    mt19937 rng;
    set<string> usedWords; // Track used words to avoid repetition
   
    // Poem structure templates
    vector<string> beginningTemplates;
    vector<string> middleTemplates;
    vector<string> endingTemplates;
    map<string, vector<string>> themeSpecificTemplates;

public:
    PoemGenerator() : rng(time(0)) {
        theme = "Technology"; // Default theme
        initializeWordBank();
        initializeTemplates();
    }

    void displayThemes() {
        cout << "\n===== Available Themes =====\n";
        cout << "1. College Life\n";
        cout << "2. Technology\n";
        cout << "3. Motivation\n";
        cout << "4. Success & Failure\n";
        cout << "5. Friendship & Memories\n";
        cout << "6. Dreams & Aspirations\n";
        cout << "7. Innovation & Creativity\n";
        cout << "8. Exams & Deadlines\n";
        cout << "9. Hustle & Productivity\n";
        cout << "10. Future & AI\n";
    }

    void selectTheme(int choice) {
        switch (choice) {
            case 1: theme = "College Life"; break;
            case 2: theme = "Technology"; break;
            case 3: theme = "Motivation"; break;
            case 4: theme = "Success & Failure"; break;
            case 5: theme = "Friendship & Memories"; break;
            case 6: theme = "Dreams & Aspirations"; break;
            case 7: theme = "Innovation & Creativity"; break;
            case 8: theme = "Exams & Deadlines"; break;
            case 9: theme = "Hustle & Productivity"; break;
            case 10: theme = "Future & AI"; break;
            default: theme = "Technology"; // Default case
        }
        initializeWordBank();
    }

    void initializeTemplates() {
        // General beginning templates
        beginningTemplates = {
            "In the world of [WORD]",
            "The [WORD] begins with [WORD]",
            "When [WORD] meets [WORD]",
            "Amidst the [WORD]",
            "Beyond the [WORD]",
            "Through endless [WORD]",
            "Seeking [WORD] in [WORD]",
            "The [WORD] of our [WORD]",
            "As [WORD] unfolds",
            "With each [WORD]"
        };

        // General middle templates
        middleTemplates = {
            "We find [WORD] and [WORD]",
            "[WORD] transforms into [WORD]",
            "Creating [WORD] that [WORD]",
            "The [WORD] continues to [WORD]",
            "Every [WORD] reveals new [WORD]",
            "[WORD] shapes our [WORD]",
            "Between [WORD] and [WORD]",
            "We discover [WORD] within [WORD]",
            "[WORD] becomes our [WORD]",
            "Through [WORD] we embrace [WORD]"
        };

        // General ending templates
        endingTemplates = {
            "Until [WORD] becomes [WORD]",
            "Finding [WORD] at last",
            "The [WORD] of tomorrow",
            "Forever in [WORD]",
            "This is our [WORD]",
            "We become the [WORD]",
            "And [WORD] remains",
            "The [WORD] never ends",
            "Our [WORD] awaits",
            "Into the [WORD] of [WORD]"
        };

        // Theme-specific templates
        themeSpecificTemplates["College Life"] = {
            "Late nights in the [WORD]",
            "From [WORD] to [WORD] we learn",
            "[WORD] before the final [WORD]",
            "The [WORD] of campus [WORD]"
        };

        themeSpecificTemplates["Technology"] = {
            "Digital [WORD] evolving",
            "The [WORD] of our [WORD] future",
            "When [WORD] meets [WORD] innovation",
            "[WORD] transforming into [WORD]"
        };

        themeSpecificTemplates["Motivation"] = {
            "Through [WORD] find your [WORD]",
            "Never stop your [WORD]",
            "Rise above the [WORD]",
            "The [WORD] inside drives [WORD]"
        };

        themeSpecificTemplates["Success & Failure"] = {
            "After [WORD] comes [WORD]",
            "Fall down, [WORD], rise again",
            "The [WORD] before the [WORD]",
            "From [WORD] to [WORD] journey"
        };

        themeSpecificTemplates["Friendship & Memories"] = {
            "Shared [WORD] create lasting [WORD]",
            "The [WORD] of [WORD] together",
            "In your [WORD] I find [WORD]",
            "[WORD] of moments we [WORD]"
        };

        themeSpecificTemplates["Dreams & Aspirations"] = {
            "Reach for the [WORD]",
            "Beyond the [WORD] lies [WORD]",
            "The [WORD] of tomorrow's [WORD]",
            "When [WORD] becomes [WORD]"
        };

        themeSpecificTemplates["Innovation & Creativity"] = {
            "The [WORD] of new [WORD]",
            "Creating [WORD] from [WORD]",
            "Reimagine the [WORD]",
            "Breaking the [WORD] of [WORD]"
        };

        themeSpecificTemplates["Exams & Deadlines"] = {
            "Racing against [WORD]",
            "The [WORD] before the [WORD]",
            "Midnight [WORD] and [WORD]",
            "From [WORD] to final [WORD]"
        };

        themeSpecificTemplates["Hustle & Productivity"] = {
            "The daily [WORD] of [WORD]",
            "Building [WORD] with each [WORD]",
            "Through [WORD] to [WORD]",
            "The [WORD] of constant [WORD]"
        };

        themeSpecificTemplates["Future & AI"] = {
            "The [WORD] of digital [WORD]",
            "When [WORD] meets human [WORD]",
            "Beyond [WORD] into [WORD]",
            "[WORD] evolving into [WORD]"
        };
    }

    void initializeWordBank() {
        if (theme == "College Life") {
            wordBank = {
                "lecture", "dorm", "coffee", "exams", "notebook", "graduation", "campus",
                "library", "hustle", "canteen", "deadline", "professor", "success",
                "memories", "sleepless", "curiosity", "friendship", "journey", "last-minute",
                "chalkboard", "knowledge", "scribble", "wisdom", "goals", "group-projects",
                "presentation", "debate", "internship", "aspirations", "textbooks"
            };
        }
        else if (theme == "Technology") {
            wordBank = {
                "algorithm", "cyber", "blockchain", "circuit", "data", "cloud", "innovation",
                "automation", "encryption", "matrix", "neural", "quantum", "cybernetics",
                "virtual", "smart", "singularity", "code", "system", "pixels", "robotics",
                "evolution", "intelligence", "sensors", "progress", "digital", "future",
                "deep-learning", "wired", "augmented", "network"
            };
        }
        else if (theme == "Motivation") {
            wordBank = {
                "hustle", "inspire", "achieve", "struggle", "strength", "passion", "conquer",
                "warrior", "thrive", "vision", "dedication", "dream", "courage", "rise",
                "fearless", "battle", "spark", "unstoppable", "victory", "challenge",
                "resilience", "push", "momentum", "peak", "perseverance", "growth", "unbreakable",
                "destiny", "relentless", "horizon"
            };
        }
        else if (theme == "Success & Failure") {
            wordBank = {
                "triumph", "lessons", "defeat", "growth", "fearless", "victory", "strive",
                "setback", "climb", "summit", "courage", "revival", "learning", "reflection",
                "breakthrough", "sacrifice", "fortune", "ambition", "risk", "effort", "achievement",
                "determination", "ups-and-downs", "wisdom", "rise-again", "rebuild", "fate",
                "endurance", "failure", "redemption"
            };
        }
        else if (theme == "Friendship & Memories") {
            wordBank = {
                "laughter", "forever", "adventure", "nostalgia", "bond", "together", "trust",
                "moments", "heartfelt", "kindred", "unbreakable", "echoes", "connection",
                "golden-days", "shared-secrets", "comfort", "sunshine", "midnight-talks", "infinite",
                "shoulder", "unspoken", "timeless", "side-by-side", "chapters", "footprints",
                "serendipity", "harmony", "treasure", "belonging", "journey"
            };
        }
        else if (theme == "Dreams & Aspirations") {
            wordBank = {
                "vision", "future", "hope", "journey", "sky", "stars", "infinite", "wish",
                "ambition", "thrive", "universe", "possibility", "rise", "explore", "courageous",
                "fearless", "destiny", "transformation", "clarity", "beyond", "reach", "skyline",
                "beyond-limits", "brave-steps", "shine", "break-free", "growth", "illuminate",
                "boundless", "awakening"
            };
        }
        else if (theme == "Innovation & Creativity") {
            wordBank = {
                "imagination", "discovery", "spark", "genius", "artistic", "original", "visionary",
                "bold", "unseen", "masterpiece", "breakthrough", "pioneer", "novelty", "design",
                "expression", "dreamscape", "exploration", "blueprint", "uncharted", "fantasy",
                "boundless", "illuminate", "evolve", "sculpt", "transform", "colorful", "intuition",
                "limitless", "idea-factory", "creation"
            };
        }
        else if (theme == "Exams & Deadlines") {
            wordBank = {
                "panic", "caffeine", "notes", "cramming", "tension", "focus", "library", "score",
                "time-bound", "revision", "countdown", "question-paper", "clock-ticking", "overthinking",
                "lecture-slides", "desperate", "burning-eyes", "formula-sheets", "past-papers",
                "late-nights", "success-pressure", "last-minute", "study-mode", "knowledge-test",
                "memory-game", "sleepless", "pass-or-fail", "anxiety", "preparation", "relief"
            };
        }
        else if (theme == "Hustle & Productivity") {
            wordBank = {
                "grind", "routine", "efficiency", "success", "growth", "drive", "focused", "determined",
                "results", "momentum", "hard-work", "dedication", "power-moves", "mastery", "strategy",
                "optimization", "workflow", "upgrade", "sharpen-skills", "hustle-harder", "maximize",
                "set-priorities", "achieve-goals", "blueprint", "late-nights", "brainstorm", "big-vision",
                "roadmap", "break-barriers", "progress"
            };
        }
        else if (theme == "Future & AI") {
            wordBank = {
                "machine", "future", "automation", "intelligence", "neural", "cyborg", "algorithm",
                "sci-fi", "evolution", "singularity", "digital-era", "deep-learning", "beyond-humanity",
                "virtual", "reality", "augmented", "synthetic-mind", "innovation", "code-universe",
                "new-age", "data-driven", "tech-boom", "beyond-imagination", "infinity", "quantum-leap",
                "ai-mind", "tomorrow", "shaping-destiny", "conscious-tech", "bionic"
            };
        }
    }

    // New function to add custom words to the current theme
    void addCustomWords() {
        cout << "\n===== Add Custom Words to " << theme << " =====\n";
        cout << "Enter words one by one. Type 'done' when finished.\n";
       
        string word;
        int count = 0;
       
        while (true) {
            cout << "Enter word #" << count + 1 << " (or 'done' to finish): ";
            cin >> word;
           
            // Break the loop if user is done
            if (word == "done" || word == "DONE") {
                break;
            }
           
            // Add the word to the word bank
            wordBank.push_back(word);
            count++;
           
            cout << "Added '" << word << "' to the " << theme << " theme.\n";
        }
       
        cout << "Added " << count << " custom words to the " << theme << " theme.\n";
    }

    string getRandomWord() {
        if (wordBank.empty()) {
            return "Word";
        }
       
        // Try to find a word that hasn't been used yet
        // If all words have been used, reset the used words set
        if (usedWords.size() >= wordBank.size()) {
            usedWords.clear();
        }
       
        string word;
        int attempts = 0;
        const int maxAttempts = 10; // Prevent infinite loop
       
        do {
            uniform_int_distribution<int> dist(0, wordBank.size() - 1);
            word = wordBank[dist(rng)];
            attempts++;
           
            // If we've tried too many times, just use whatever word we have
            if (attempts >= maxAttempts) {
                break;
            }
        } while (usedWords.find(word) != usedWords.end());
       
        // Mark the word as used
        usedWords.insert(word);
        return word;
    }

    string capitalizeFirstLetter(const string& word) {
        if (word.empty()) return word;
        string result = word;
        result[0] = toupper(result[0]);
        return result;
    }

    string getRandomTemplate(const vector<string>& templates) {
        uniform_int_distribution<int> dist(0, templates.size() - 1);
        return templates[dist(rng)];
    }

    string replaceTemplateWords(string templateStr) {
        size_t pos = templateStr.find("[WORD]");
        while (pos != string::npos) {
            templateStr.replace(pos, 6, capitalizeFirstLetter(getRandomWord()));
            pos = templateStr.find("[WORD]", pos + 1);
        }
        return templateStr;
    }

    string generatePoemTitle() {
        // Create a themed title
        vector<string> titleTemplates = {
            "The [WORD] of [WORD]",
            "[WORD] in the [WORD]",
            "When [WORD] Meets [WORD]",
            "Beyond the [WORD]",
            "[WORD]: A [WORD] Story",
            "The [WORD]'s [WORD]"
        };
       
        string title = getRandomTemplate(titleTemplates);
        return replaceTemplateWords(title);
    }

    // Modified generatePoem to accept custom stanza and line parameters
    string generatePoem(int customStanzas = 0, int customLinesPerStanza = 0) {
        // Clear used words for this new poem
        usedWords.clear();
       
        stringstream poemStream;
        poemStream << "\n===== " << theme << " Poem =====\n\n";
       
        string title = generatePoemTitle();
        poemStream << title << "\n\n";
       
        // Determine poem structure (number of stanzas and lines per stanza)
        uniform_int_distribution<int> stanzasDist(2, 4);
        uniform_int_distribution<int> linesDist(3, 5);
       
        int stanzas = (customStanzas > 0) ? customStanzas : stanzasDist(rng);
       
        for (int s = 0; s < stanzas; s++) {
            int lines = (customLinesPerStanza > 0) ? customLinesPerStanza : linesDist(rng);
           
            // First stanza should start with a beginning template
            if (s == 0) {
                string line = replaceTemplateWords(getRandomTemplate(beginningTemplates));
                poemStream << line << "\n";
                lines--;
            }
           
            // Last line of last stanza should be an ending template
            if (s == stanzas - 1) {
                lines--;
            }
           
            // Get theme-specific templates if available
            vector<string> themeTemplates = themeSpecificTemplates[theme];
           
            // Middle lines use mix of theme-specific and general middle templates
            for (int l = 0; l < lines; l++) {
                string line;
               
                // 60% chance to use theme-specific template if available
                uniform_int_distribution<int> templateChoice(1, 100);
                if (!themeTemplates.empty() && templateChoice(rng) <= 60) {
                    line = replaceTemplateWords(getRandomTemplate(themeTemplates));
                } else {
                    line = replaceTemplateWords(getRandomTemplate(middleTemplates));
                }
               
                poemStream << line << "\n";
            }
           
            // Last line of last stanza
            if (s == stanzas - 1) {
                string line = replaceTemplateWords(getRandomTemplate(endingTemplates));
                poemStream << line << "\n";
            }
           
            // Add stanza break except for the last stanza
            if (s < stanzas - 1) {
                poemStream << "\n";
            }
        }
        poemStream << "\n";
       
        // Print poem to console
        string poem = poemStream.str();
        cout << poem;
       
        return poem;
    }
   
    // New function to save poem to file
    void saveToFile(const string& poem) {
        string filename;
        cout << "Enter filename to save poem (e.g., mypoem.txt): ";
        cin >> filename;
       
        ofstream outFile(filename);
       
        if (outFile.is_open()) {
            outFile << poem;
            outFile.close();
            cout << "Poem saved to " << filename << " successfully!\n";
        } else {
            cout << "Error: Could not open file for writing.\n";
        }
    }
};

int main() {
    PoemGenerator generator;
    int themeChoice = 0;
    char continueChoice = 'y';
   
    cout << "=== Welcome to the Enhanced Themed Poem Generator ===\n";
   
    while (continueChoice == 'y' || continueChoice == 'Y') {
        generator.displayThemes();
        cout << "\nSelect a theme (1-10): ";
        cin >> themeChoice;
        generator.selectTheme(themeChoice);
       
        // Option to add custom words
        char addWordsChoice;
        cout << "Would you like to add custom words to this theme? (y/n): ";
        cin >> addWordsChoice;
       
        if (addWordsChoice == 'y' || addWordsChoice == 'Y') {
            generator.addCustomWords();
        }
       
        // Option to customize poem structure
        char customizeChoice;
        cout << "Would you like to customize the poem structure? (y/n): ";
        cin >> customizeChoice;
       
        int stanzas = 0;
        int linesPerStanza = 0;
       
        if (customizeChoice == 'y' || customizeChoice == 'Y') {
            cout << "Enter number of stanzas (2-6): ";
            cin >> stanzas;
            stanzas = max(2, min(6, stanzas)); // Clamp between 2 and 6
           
            cout << "Enter lines per stanza (3-8): ";
            cin >> linesPerStanza;
            linesPerStanza = max(3, min(8, linesPerStanza)); // Clamp between 3 and 8
        }
       
        // Generate the poem with optional custom structure
        string poem = generator.generatePoem(stanzas, linesPerStanza);
       
        // Option to save poem to file
        char saveChoice;
        cout << "Would you like to save this poem to a file? (y/n): ";
        cin >> saveChoice;
       
        if (saveChoice == 'y' || saveChoice == 'Y') {
            generator.saveToFile(poem);
        }
       
        cout << "Generate another poem? (y/n): ";
        cin >> continueChoice;
    }
   
    cout << "\nThank you for using the Enhanced Themed Poem Generator!\n";
    return 0;
}
