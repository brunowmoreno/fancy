FancySpec describe: "S-Expression" for: String with: |it| {
  it should: "be correct for assignment" for: 'to_sexp when: {
    "x = 3" to_sexp should == ['assign, ['ident, 'x], ['int_lit, 3]];
    "foobar = nil" to_sexp should == ['assign, ['ident, 'foobar], ['ident, 'nil]]
  };

  it should: "be correct for symbol literals" for: 'to_sexp when: {
    "'foo" to_sexp should == ['symbol_lit, 'foo]
  };

  it should: "be correct for string literals" for: 'to_sexp when: {
#    "\"foo\"" to_sexp should == ['string_lit, "foo"]
  };

  it should: "be correct for integer literals" for: 'to_sexp when: {
    "3" to_sexp should == ['int_lit, 3];
    "-3" to_sexp should == ['int_lit, -3];
    "0" to_sexp should == ['int_lit, 0]
  };

  it should: "be correct for double literals" for: 'to_sexp when: {
    "3.5" to_sexp should == ['double_lit, 3.5];
    "-3.5" to_sexp should == ['double_lit, -3.5];
    "0.0" to_sexp should == ['double_lit, 0.0]
  };

  it should: "be correct for array literals" for: 'to_sexp when: {
    "[1,2,3]" to_sexp should == ['array_lit, [['int_lit, 1], ['int_lit, 2], ['int_lit, 3]]];

    "[[1,2],[3,4]]" to_sexp should ==
        ['array_lit, [['array_lit, [['int_lit, 1], ['int_lit, 2]]],
                      ['array_lit, [['int_lit, 3], ['int_lit, 4]]]]];

    "[]" to_sexp should == ['array_lit, []]
  }
}
