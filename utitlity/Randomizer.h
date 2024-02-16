#pragma once
#include"../src/pch.h"

template<typename IntegerType = int, typename RealType = double>
class Randomizer
{
public:
	Randomizer();
	Randomizer(IntegerType first_of_range, IntegerType last_of_range);

	void SetRangeInt(IntegerType first_of_range, IntegerType last_of_range);
	void SetRangeReal(RealType first_of_range, RealType last_of_range);

	IntegerType GetInt()const;
	IntegerType GetInt(unsigned seed)const;

	RealType GetReal()const;
	RealType GetReal(unsigned seed)const;

	void SetSeed(unsigned seed);

private:
	 std::random_device rd;
	 std::mt19937 m_generator;
	 std::uniform_int_distribution<IntegerType> m_int_distribution;
	 std::uniform_real_distribution<RealType> m_real_distribution;
};

template<typename IntegerType, typename RealType>
inline Randomizer<IntegerType, RealType>::Randomizer()
	:m_generator(rd()), m_int_distribution(0, 0), m_real_distribution(0, 0)
{ }

template<typename IntegerType, typename RealType>
inline Randomizer<IntegerType, RealType>::Randomizer(IntegerType first_of_range, IntegerType last_of_range)
	: Randomizer()
{
	SetRangeInt(first_of_range, last_of_range);
}

template<typename IntegerType, typename RealType>
inline void Randomizer<IntegerType, RealType>::SetRangeInt(IntegerType first_of_range, IntegerType last_of_range)
{
	if (first_of_range > last_of_range)
		std::swap(first_of_range, last_of_range);

	m_int_distribution.param(std::uniform_int_distribution<IntegerType>::param_type(first_of_range, last_of_range));
}

template<typename IntegerType, typename RealType>
inline void Randomizer<IntegerType, RealType>::SetRangeReal(RealType first_of_range, RealType last_of_range)
{
	if (first_of_range > last_of_range)
		std::swap(first_of_range, last_of_range);

	m_real_distribution.param(std::uniform_real_distribution<RealType>::param_type(first_of_range, last_of_range));
}

template<typename IntegerType, typename RealType>
inline IntegerType Randomizer<IntegerType, RealType>::GetInt()const
{
	return m_int_distribution(m_generator);
}

template<typename IntegerType, typename RealType>
inline IntegerType Randomizer<IntegerType, RealType>::GetInt(unsigned seed)const
{
	m_generator.seed(seed);

	return m_int_distribution(m_generator);
}

template<typename IntegerType, typename RealType>
inline RealType Randomizer<IntegerType, RealType>::GetReal()const
{
	return m_real_distribution(m_generator);
}

template<typename IntegerType, typename RealType>
inline RealType Randomizer<IntegerType, RealType>::GetReal(unsigned seed)const
{
	m_generator.seed(seed);

	return m_real_distribution(m_generator);
}

template<typename IntegerType, typename RealType>
inline void Randomizer<IntegerType, RealType>::SetSeed(unsigned seed)
{
	m_generator.seed(seed);
}
