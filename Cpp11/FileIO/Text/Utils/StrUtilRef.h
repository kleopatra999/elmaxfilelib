#pragma once

//#include "DataType.h"
#include "DataTypeRef.h"
#include "SplitStrategy.h"
#include "../Stream/ostream.h"

namespace Elmax
{

class StrUtilRef
{
public:
	StrUtilRef(void);
	~StrUtilRef(void);

	static std::wstring Format( std::wstring fmt, size_t )
	{
		return fmt;
	}

	template<typename T, typename... Args>
	static std::wstring Format( std::wstring fmt, size_t index, T& t, Args&... args )
	{
		ostream os;
		os << t;
		std::wstring result = Replace( fmt, index, os.str() );

		++index;

		std::wstring str = Format( result, index, args... );

		return str;
	}

private:
	static std::wstring Replace( std::wstring fmtstr, std::vector<std::wstring>& vs );

	static std::wstring Replace( std::wstring fmtstr, size_t index, const std::wstring& s );

	static std::wstring Anchor( int i );
public:
	void SetSplitStrategy( ISplitStrategy* pSplitStrategy )
	{
		m_pSplitStrategy = pSplitStrategy;
	}

private:
	ISplitStrategy* m_pSplitStrategy;
};

}