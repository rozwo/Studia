//    int NWW(int l, int m);
//    int Skroc(int64_t, int64_t); //why?
// do tamtej klasy

// class Bledy : public exception
// {
//   protected:
//     string tresc;
//   public:
//     Bledy() = default;
// };

// class NieDzielPrzezZero : public Bledy
// {
//   public:
//     NieDzielPrzezZero() = default;
//     NieDzielPrzezZero(const char* t);
//     NieDzielPrzezZero(const NieDzielPrzezZero &c) = default;
//     NieDzielPrzezZero & operator = (const NieDzielPrzezZero &tb) = default;
//     virtual const char* what();
//     virtual ~NieDzielPrzezZero() = default;
// };

// class PrzekroczonoZakres : public Bledy
// {
//   public:
//     PrzekroczonoZakres() = default;
//     PrzekroczonoZakres(const char* t);
//     PrzekroczonoZakres(const PrzekroczonoZakres &c) = default;
//     PrzekroczonoZakres & operator = (const PrzekroczonoZakres &tb) = default;
//     virtual const char* what();
//     virtual ~PrzekroczonoZakres() = default;
// };