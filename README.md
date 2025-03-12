# Poem-Generator
Our system generates contextually relevant poems by:

1. Allowing users to choose a theme (Love, Nature, Motivation, etc.).
2. Selecting and shuffling words from a pre-defined word bank relevant to the theme.
3. Using structured templates to form coherent and aesthetically pleasing poems.
4. Ensuring word uniqueness and randomization for fresh outputs every time.

The result? A high-quality, AI-assisted poem that feels personal and engaging!

##Key Features 

1. Multiple Themes – Users can select different categories, such as Romance, Adventure, and Inspiration.
2. Dynamic Word Selection – Ensures that each poem is unique and contextually relevant.
3. Template-Based Poem Structuring – Maintains poetic rhythm and readability.
4. Randomization for Creativity – No two poems are exactly alike.
5. User-Friendly Console Interface – Simple input prompts for easy interaction.
6. Future Scope: AI-Generated Poetry Refinements – Can be improved using NLP techniques like GPT for even more natural poetry generation.

##Technical Overview

Programming Language: C++
Data Structures Used:
vector for word bank storage.
unordered_map for theme-specific templates.
set to track and prevent word repetition.


##Algorithm Flow:

1. User selects a theme.


2. Relevant words are pulled from a pre-defined dataset.


3. A template poem is chosen, and placeholders are dynamically replaced with selected words.


4. The final poem is printed beautifully to the console.

   ##Randomization Techniques:

1.Uses Mersenne Twister (mt19937) for unpredictable word selection.
2.Implements shuffle to mix words for variation.


##Error Handling:

1.Ensures non-repetitive word usage.

2.Prevents empty input errors and incorrect theme selections.

3.Market & Future Scope 

*This project has potential beyond just a console-based application. Future improvements can include*:
Integration with AI/ML models for deep learning-based poem generation.
Customization Features allowing users to input specific names, emotions, and preferences.


With advancements in AI, this project could evolve into an AI-powered poetry assistant, helping writers, students, and enthusiasts craft unique literary pieces effortlessly.



