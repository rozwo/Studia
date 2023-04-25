# Róża Wójcicka
# lista 8: zadanie 2
# jezyk Ruby
# w Ruby Mine

class Czas
  def initialize(t)
    @min = t
  end
  def h
    @min / 60
  end
  def s
    @min * 60
  end
  def to_s
    @min.to_s
  end
end

class Dlugosc
  def initialize(d)
    @metr = d
  end
  def km
    @metr / 1000
  end
  def mm
    @metr * 0.00054
  end
  def to_s
    @metr.to_s
  end
end

class Predkosc
  def initialize(x, y)
    @s = Dlugosc.new(x)
    @t = Czas.new(y)
  end
  def km_h
    if(@t.h.to_f == 0)
      "dzielenie przez zero"
    else
      @s.km.to_f / @t.h.to_f
    end
  end
  def wezly
    if(@t.h.to_f == 0)
      "dzielenie przez zero"
    else
      @s.mm.to_f / @t.h.to_f
    end
  end
end

class Przyspieszenie
  def initialize(x, y)
    @s = Dlugosc.new(x)
    @t = Czas.new(y)
  end
  def km_s2
    if(@t.s.to_f == 0)
      "dzielenie przez zero"
    else
      @s.km.to_f / (@t.s.to_f * @t.s.to_f)
    end
  end
  def mm_h2
    if(@t.h.to_f == 0)
      "dzielenie przez zero"
    else
      @s.mm.to_f / (@t.h.to_f * @t.h.to_f)
    end
  end
end

v = Predkosc.new(200000000,3000)
printf "Predkosc: #{v.km_h} km/h to #{v.wezly} wezlow\n"

a = Przyspieszenie.new(90000000,700)
printf "Przyspieszenie: #{a.km_s2} km/s2 to #{a.mm_h2} mm/h2\n"
