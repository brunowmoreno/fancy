FancySpec describe: "ARGV & predefined values" with: |it| {
  it should: "have ARGV correctly defined" when: {
    ARGV empty? should_not == true
  };

  it should: "have a __FILE__ variable defined" when: {
    __FILE__ should_not == nil
  };

  it should: "have the __FILE__ value be an element in ARGV" when: {
    ARGV include?: __FILE__ . should == true
  }
}
