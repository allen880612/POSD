class Article {
   public:
    virtual ~Article(){};

    virtual std::string getText() const = 0;

    virtual int getLevel() const {}

    virtual void add(Article* dpFormat){};
};