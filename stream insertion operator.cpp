template <typename T, typename P>
struct Map {
private:
    friend std::ostream& operator<< <>(std::ostream&, const Map<T, P>&);

    T m_key;
    P m_value;

public:
    Map(T key, P value)
        : m_key(key), m_value(value) {}

};

template <typename T, typename P>
std::ostream& operator<<(std::ostream& os, const Map<T, P>& map) {
    os << "Map : [" << map.m_key << "," << map.m_value << "]";
    return os;
}
