#include "../../include/Algorithms/SortingAlgorithm.hpp"

namespace Sorting {

    /*************************************************************************************************
     *************************************** Public Functions ****************************************
     *************************************************************************************************/

    /**
     * @brief Updates Scene: Runs an step of the algorithm until it is sorted.
     * 
     */
    void SortingAlgorithm::update() {
        if (!is_sorted())
            sort();
        else if (is_sorted() && currentIndex > 0)
            complete();
    }

    /**
     * @brief Render cycle: Draws data onto screen.
     * 
     * @param sf::RenderWindow& window 
     */
    void SortingAlgorithm::render(sf::RenderWindow& window) {
        window.clear(sf::Color::Black);

        for (int i = 0; i < length; i++)
            window.draw(data[i]);
    }

    /**
     * @brief Resets data back to beginning.
     * 
     */
    void SortingAlgorithm::restart() {
        delete[] data;
        generate_data();
        set_default();
    }

    /**
     * @brief Returns if algorithm is sorted or not.
     * 
     * @return true | false 
     */
    bool SortingAlgorithm::is_sorted() {
        return sorted;
    }

    /*************************************************************************************************
     *************************************** Protected Functions *************************************
     *************************************************************************************************/

    /**
     * @brief Generates random (non-repetitive) data to populate dynamic array.
     * 
     */
    void SortingAlgorithm::generate_data() {
        data = new sf::RectangleShape[length];
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(1, HEIGHT);

        for (int i = 0; i < length; i++) {
            int value = dist(rng);
            data[i] = sf::RectangleShape(sf::Vector2f(dataWidth, value));
            data[i].setFillColor(sf::Color::White);
            data[i].setPosition(sf::Vector2f(dataWidth *  (i+1), HEIGHT));
            data[i].setRotation(180);
        }
    }

    /**
     * @brief Swaps y (height) values between passes in data.
     * 
     * @param A 
     * @param B 
     */
    void SortingAlgorithm::swap(sf::RectangleShape& A, sf::RectangleShape& B) {
        int tempX = A.getSize().x;
        int tempY = A.getSize().y;

        A.setSize(
            sf::Vector2f(
                B.getSize().x, B.getSize().y
            )
        );

        B.setSize(
            sf::Vector2f(
                tempX, tempY
            )
        );
    }

    /**
     * @brief Changes all data to Green fillColor to show data is sorted.
     * 
     */
    void SortingAlgorithm::complete() {
        data[length - currentIndex].setFillColor(sf::Color::Green);
        currentIndex--;
        sf::sleep(sf::milliseconds(5));
    }
}