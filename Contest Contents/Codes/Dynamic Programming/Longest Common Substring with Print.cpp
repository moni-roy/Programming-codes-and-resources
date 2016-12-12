void findSubstrings ( const string &s, set< string> &p ) {
    int l = s.length( ) ;
    for ( int i = 0 ; i < l ; i++ ) {
        for ( int j = 1 ; j < l - i + 1 ; j++ ) {
            p.insert ( s.substr( i, j ) ) ;
        }
    }
}
string lcs ( const string & s1, const  string & s2 ) {
    set< string> sub1, sub2 ;
    findSubstrings ( s1, sub1 ) ;
    findSubstrings ( s2, sub2 ) ;
    set< string> common ;
    set_intersection ( sub1.begin( ), sub1.end( ),
                       sub2.begin( ), sub2.end( ),
                       inserter ( common, common.begin( ) ) ) ;
    vector< string> commonSubs ( common.begin( ), common.end( ) ) ;
    sort ( commonSubs.begin( ), commonSubs.end( ),
    []( const  string &s1,const  string &s2 ) {
        return s1.length( ) > s2.length( ) ;
    } ) ;
    if(commonSubs.size()==0) return "";
    return *(commonSubs.begin( ) ) ;
}
