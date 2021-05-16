#pragma once

/**
 * @file
 * Contains auxillary functions processing input string to
 * vector of words (removing whitespaces)
 */

#include <string>
#include <sstream>
#include <vector>
#include <iterator>


/** namespace with auxillary string processing functions */
namespace StringSplit {

    /**
     * splits string by eliminating ' ' occurences
     * and then saves substrings to result
     * @param std::string
     * @param char
     * @param typename Out
     */
    template <typename Out>
    void split(const std::string &s, Out result) {
        std::istringstream iss(s);
        std::string item;
        while (std::getline(iss, item, ' ')) {
        	if (!item.empty() && item != " ") {
        		*result++ = item;
        	}
        }
    }

    /**
     * splits string by eliminating ' ' occurences
     * and returns it as std::vector of words
     * @param std::string
     * @param char
     * @return std::vector<std::string>
     */
    std::vector<std::string> split(const std::string &s) {
        std::vector<std::string> elems;
        split(s, std::back_inserter(elems));
        return elems;
    }

}