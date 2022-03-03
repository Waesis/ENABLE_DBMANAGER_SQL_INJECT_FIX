Search : m_sql.AsyncQuery(szQuery);

Change :
#ifdef ENABLE_DBMANAGER_SQL_INJECT_FIX
	std::string sQuery(szQuery);
	m_sql.AsyncQuery(sQuery.substr(0, sQuery.find_first_of(";") == std::string::npos ? sQuery.length() : sQuery.find_first_of(";")).c_str());
#else
	m_sql.AsyncQuery(szQuery);
#endif


Search : return m_sql_direct.DirectQuery(szQuery);

Change :
#ifdef ENABLE_DBMANAGER_SQL_INJECT_FIX
	std::string sQuery(szQuery);
    return m_sql_direct.DirectQuery(sQuery.substr(0, sQuery.find_first_of(";") == std::string::npos ? sQuery.length() : sQuery.find_first_of(";")).c_str());
#else
	return m_sql_direct.DirectQuery(szQuery);
#endif
