#include <unordered_map>

/*
 * Проход по массиву один раз. Для каждого элемента вычисляем, какое число нужно ещё (target - nums[i]), и смотрим,
 * встречалось ли оно раньше (в хэш-таблице). Если да — вернули индексы. Если нет — сохраняем текущий элемент и
 * продолжаем.
 */
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        
        std::unordered_map<int, int> map; //создаем карту. Ключ - значение из nums, значение - индекс значения 
        for (int i = 0; i < nums.size(); i++) //бежим по вектору
        {
            int complement = target - nums[i]; // создаем комплемент
            
            if(map.find(complement) != map.end()) // если комплемент есть в мапе map.find(key) возвращает итератор на элемент, если найден, или map.end(), если ключа нет.
            {
                return {map[complement], i}; //возвращаем map [complement] - индекс элемента который есть в мапе, i - индекс текущего элемента
            }
            map [nums[i]] = i; //если не найден - создаем пару в мапе: значение из массива, его индекс
        }
        return {-1,-1};
    }
};
