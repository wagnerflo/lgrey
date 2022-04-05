template<class T> class validator {
  public:
    virtual bool accepts(const T&) const { return true; }
    virtual ~validator() { /* empty */ }
};

template<class T, class U> class function_validator : public validator<T> {
  protected:
    const U _func;

  public:
    function_validator(const U& f) : _func(f) { /* empty */ }
    virtual bool accepts(const T& value) const { return _func(value); }
};

template<class T> class valueopt : public propa_detail::optbase {
  // ...

  protected:
    std::vector<validator<T>*> _validators;

  private:
    const T& validate(const T& value) const {
      for(typename std::vector<validator<T>*>::const_iterator it =
            _validators.begin(); it != _validators.end(); ++it)
        if(!(*it)->accepts(value))
          throw std::runtime_error("value not valid");

      return value;
    }

    virtual void set(const std::string& v) { _ref = validate(_conv(v)); }

  // ....

  public:
    valueopt<T>& range(const T& min, const T& max) {
      return greater_equal(min).less_equal(max);
    }

    valueopt<T>& greater(const T& min) {
      _validators.push_back(
        new function_validator<T,std::binder2nd<std::greater<T> > >(
          std::binder2nd<std::greater<T> >(std::greater<T>(), min)));
      return *this;
    }

    valueopt<T>& greater_equal(const T& min) {
      _validators.push_back(
        new function_validator<T,std::binder2nd<std::greater_equal<T> > >(
          std::binder2nd<std::greater_equal<T> >(
            std::greater_equal<T>(), min)));
      return *this;
    }

    valueopt<T>& less(const T& max) {
      _validators.push_back(
        new function_validator<T,std::binder2nd<std::less<T> > >(
          std::binder2nd<std::less<T> >(std::less<T>(), max)));
      return *this;
    }

    valueopt<T>& less_equal(const T& max) {
      _validators.push_back(
         new function_validator<T,std::binder2nd<std::less_equal<T> > >(
          std::binder2nd<std::less_equal<T> >(std::less_equal<T>(), max)));
      return *this;
    }

  // ...
};
