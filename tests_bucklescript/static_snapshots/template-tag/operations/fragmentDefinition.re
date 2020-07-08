[@ocaml.ppx.context
  {
    tool_name: "migrate_driver",
    include_dirs: [],
    load_path: [],
    open_modules: [],
    for_package: None,
    debug: false,
    use_threads: false,
    use_vmthreads: false,
    recursive_types: false,
    principal: false,
    transparent_modules: false,
    unboxed_types: false,
    unsafe_string: false,
    cookies: [],
  }
];
module GraphQL_PPX = {
  let deepMerge = (json1, _) => json1;
};
module ListFragment = {
  [@ocaml.warning "-32"];
  module Raw = {
    type t = {
      nullableOfNullable: Js.Nullable.t(array(Js.Nullable.t(string))),
      nullableOfNonNullable: Js.Nullable.t(array(string)),
    };
    type nonrec t_Lists = t;
  };
  type t = {
    nullableOfNullable: option(array(option(string))),
    nullableOfNonNullable: option(array(string)),
  };
  type nonrec t_Lists = t;
  /**The GraphQL query string*/
  let query: string = [%raw
    "require(\"gql\")`\n  fragment ListFragment on Lists   {\n    nullableOfNullable\n    nullableOfNonNullable\n  }\n`"
  ];
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => (
    {
      nullableOfNullable: {
        let value = (value: Raw.t).nullableOfNullable;
        switch (Js.toOption(value)) {
        | Some(value) =>
          Some(
            value
            |> Js.Array.map(value =>
                 switch (Js.toOption(value)) {
                 | Some(value) => Some(value)
                 | None => None
                 }
               ),
          )
        | None => None
        };
      },
      nullableOfNonNullable: {
        let value = (value: Raw.t).nullableOfNonNullable;
        switch (Js.toOption(value)) {
        | Some(value) => Some(value |> Js.Array.map(value => value))
        | None => None
        };
      },
    }: t
  );

  let verifyArgsAndParse =
      (~fragmentName as _ListFragment: [ | `ListFragment], value: Raw.t) =>
    parse(value);
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => (
    {
      let nullableOfNonNullable = {
        let value = (value: t).nullableOfNonNullable;
        switch (value) {
        | Some(value) =>
          Js.Nullable.return(value |> Js.Array.map(value => value))
        | None => Js.Nullable.null
        };
      }
      and nullableOfNullable = {
        let value = (value: t).nullableOfNullable;
        switch (value) {
        | Some(value) =>
          Js.Nullable.return(
            value
            |> Js.Array.map(value =>
                 switch (value) {
                 | Some(value) => Js.Nullable.return(value)
                 | None => Js.Nullable.null
                 }
               ),
          )
        | None => Js.Nullable.null
        };
      };
      {nullableOfNullable, nullableOfNonNullable};
    }: Raw.t
  );
  let verifyName =
    fun
    | `ListFragment => ();
  external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
  external toJson: Raw.t => Js.Json.t = "%identity";
  module Z__INTERNAL = {
    type root = t;
    type nonrec graphql;
    /**```
Lists {
  nullableOfNullable: [String]
  nullableOfNonNullable: [String!]
  nonNullableOfNullable: [String]!
  nonNullableOfNonNullable: [String!]!
  listWithArg: [String]
}
```*/
    let graphql: graphql = Obj.magic(0);
    type nonrec graphql_module;
    /****--- graphql-ppx module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module GraphQL {
  /**
  The GraphQL query string
  */
  let query: string;

  /**
  This is the main type of the result you will get back.
  You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  */
  type t;

  /**
  Parse the JSON GraphQL data to ReasonML data types
  */
  let parse: Raw.t => t;

  /**
  Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data
  */
  let serialize: t => Raw.t;

  /**
  This is the JSON compatible type of the GraphQL data.
  It should not be necessary to access the types inside for normal use cases.
  */
  module Raw: { type t; };
}
```*/
    let graphql_module: graphql_module = Obj.magic(0);
  };
};
module Another = {
  [@ocaml.warning "-32"];
  module Raw = {
    type t = {nullableOfNonNullable: Js.Nullable.t(array(string))};
    type nonrec t_Lists = t;
  };
  type t = {nullableOfNonNullable: option(array(string))};
  type nonrec t_Lists = t;
  /**The GraphQL query string*/
  let query: string = [%raw
    "require(\"gql\")`\n  fragment Another on Lists   {\n    nullableOfNonNullable\n  }\n`"
  ];
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => (
    {
      nullableOfNonNullable: {
        let value = (value: Raw.t).nullableOfNonNullable;
        switch (Js.toOption(value)) {
        | Some(value) => Some(value |> Js.Array.map(value => value))
        | None => None
        };
      },
    }: t
  );

  let verifyArgsAndParse =
      (~fragmentName as _Another: [ | `Another], value: Raw.t) =>
    parse(value);
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => (
    {
      let nullableOfNonNullable = {
        let value = (value: t).nullableOfNonNullable;
        switch (value) {
        | Some(value) =>
          Js.Nullable.return(value |> Js.Array.map(value => value))
        | None => Js.Nullable.null
        };
      };
      {nullableOfNonNullable: nullableOfNonNullable};
    }: Raw.t
  );
  let verifyName =
    fun
    | `Another => ();
  external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
  external toJson: Raw.t => Js.Json.t = "%identity";
  module Z__INTERNAL = {
    type root = t;
    type nonrec graphql;
    /**```
Lists {
  nullableOfNullable: [String]
  nullableOfNonNullable: [String!]
  nonNullableOfNullable: [String]!
  nonNullableOfNonNullable: [String!]!
  listWithArg: [String]
}
```*/
    let graphql: graphql = Obj.magic(0);
    type nonrec graphql_module;
    /****--- graphql-ppx module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module GraphQL {
  /**
  The GraphQL query string
  */
  let query: string;

  /**
  This is the main type of the result you will get back.
  You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  */
  type t;

  /**
  Parse the JSON GraphQL data to ReasonML data types
  */
  let parse: Raw.t => t;

  /**
  Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data
  */
  let serialize: t => Raw.t;

  /**
  This is the JSON compatible type of the GraphQL data.
  It should not be necessary to access the types inside for normal use cases.
  */
  module Raw: { type t; };
}
```*/
    let graphql_module: graphql_module = Obj.magic(0);
  };
};
module FragmentWithArgs = {
  [@ocaml.warning "-32"];
  module Raw = {
    type t = {listWithArg: Js.Nullable.t(array(Js.Nullable.t(string)))};
    type nonrec t_Lists = t;
  };
  type t = {listWithArg: option(array(option(string)))};
  type nonrec t_Lists = t;
  /**The GraphQL query string*/
  let query: string = [%raw
    "require(\"gql\")`\n  fragment FragmentWithArgs on Lists   {\n    listWithArg(arg1: $arg1)\n  }\n`"
  ];
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => (
    {
      listWithArg: {
        let value = (value: Raw.t).listWithArg;
        switch (Js.toOption(value)) {
        | Some(value) =>
          Some(
            value
            |> Js.Array.map(value =>
                 switch (Js.toOption(value)) {
                 | Some(value) => Some(value)
                 | None => None
                 }
               ),
          )
        | None => None
        };
      },
    }: t
  );

  let verifyArgsAndParse =
      (
        ~arg1 as _arg1: [ | `String],
        ~fragmentName as _FragmentWithArgs: [ | `FragmentWithArgs],
        value: Raw.t,
      ) =>
    parse(value);
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => (
    {
      let listWithArg = {
        let value = (value: t).listWithArg;
        switch (value) {
        | Some(value) =>
          Js.Nullable.return(
            value
            |> Js.Array.map(value =>
                 switch (value) {
                 | Some(value) => Js.Nullable.return(value)
                 | None => Js.Nullable.null
                 }
               ),
          )
        | None => Js.Nullable.null
        };
      };
      {listWithArg: listWithArg};
    }: Raw.t
  );
  let verifyName =
    fun
    | `FragmentWithArgs => ();
  external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
  external toJson: Raw.t => Js.Json.t = "%identity";
  module Z__INTERNAL = {
    type root = t;
    type nonrec graphql;
    /**```
Lists {
  nullableOfNullable: [String]
  nullableOfNonNullable: [String!]
  nonNullableOfNullable: [String]!
  nonNullableOfNonNullable: [String!]!
  listWithArg: [String]
}
```*/
    let graphql: graphql = Obj.magic(0);
    type nonrec graphql_module;
    /****--- graphql-ppx module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module GraphQL {
  /**
  The GraphQL query string
  */
  let query: string;

  /**
  This is the main type of the result you will get back.
  You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  */
  type t;

  /**
  Parse the JSON GraphQL data to ReasonML data types
  */
  let parse: Raw.t => t;

  /**
  Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data
  */
  let serialize: t => Raw.t;

  /**
  This is the JSON compatible type of the GraphQL data.
  It should not be necessary to access the types inside for normal use cases.
  */
  module Raw: { type t; };
}
```*/
    let graphql_module: graphql_module = Obj.magic(0);
  };
};

module InlineListFragment = {
  [@ocaml.warning "-32"];
  module Raw = {
    type t = {
      nullableOfNullable: Js.Nullable.t(array(Js.Nullable.t(string))),
      nullableOfNonNullable: Js.Nullable.t(array(string)),
    };
    type nonrec t_Lists = t;
  };
  type t = {
    nullableOfNullable: option(array(option(string))),
    nullableOfNonNullable: option(array(string)),
  };
  type nonrec t_Lists = t;
  /**The GraphQL query string*/
  let query: string = [%raw
    "require(\"gql\")`\n  fragment InlineListFragment on Lists   {\n    nullableOfNullable\n    nullableOfNonNullable\n  }\n`"
  ];
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => (
    {
      nullableOfNullable: {
        let value = (value: Raw.t).nullableOfNullable;
        switch (Js.toOption(value)) {
        | Some(value) =>
          Some(
            value
            |> Js.Array.map(value =>
                 switch (Js.toOption(value)) {
                 | Some(value) => Some(value)
                 | None => None
                 }
               ),
          )
        | None => None
        };
      },
      nullableOfNonNullable: {
        let value = (value: Raw.t).nullableOfNonNullable;
        switch (Js.toOption(value)) {
        | Some(value) => Some(value |> Js.Array.map(value => value))
        | None => None
        };
      },
    }: t
  );

  let verifyArgsAndParse =
      (
        ~fragmentName as _InlineListFragment: [ | `InlineListFragment],
        value: Raw.t,
      ) =>
    parse(value);
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => (
    {
      let nullableOfNonNullable = {
        let value = (value: t).nullableOfNonNullable;
        switch (value) {
        | Some(value) =>
          Js.Nullable.return(value |> Js.Array.map(value => value))
        | None => Js.Nullable.null
        };
      }
      and nullableOfNullable = {
        let value = (value: t).nullableOfNullable;
        switch (value) {
        | Some(value) =>
          Js.Nullable.return(
            value
            |> Js.Array.map(value =>
                 switch (value) {
                 | Some(value) => Js.Nullable.return(value)
                 | None => Js.Nullable.null
                 }
               ),
          )
        | None => Js.Nullable.null
        };
      };
      {nullableOfNullable, nullableOfNonNullable};
    }: Raw.t
  );
  let verifyName =
    fun
    | `InlineListFragment => ();
  external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
  external toJson: Raw.t => Js.Json.t = "%identity";
  module Z__INTERNAL = {
    type root = t;
    type nonrec graphql;
    /**```
Lists {
  nullableOfNullable: [String]
  nullableOfNonNullable: [String!]
  nonNullableOfNullable: [String]!
  nonNullableOfNonNullable: [String!]!
  listWithArg: [String]
}
```*/
    let graphql: graphql = Obj.magic(0);
    type nonrec graphql_module;
    /****--- graphql-ppx module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module GraphQL {
  /**
  The GraphQL query string
  */
  let query: string;

  /**
  This is the main type of the result you will get back.
  You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  */
  type t;

  /**
  Parse the JSON GraphQL data to ReasonML data types
  */
  let parse: Raw.t => t;

  /**
  Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data
  */
  let serialize: t => Raw.t;

  /**
  This is the JSON compatible type of the GraphQL data.
  It should not be necessary to access the types inside for normal use cases.
  */
  module Raw: { type t; };
}
```*/
    let graphql_module: graphql_module = Obj.magic(0);
  };
};
module MyQuery = {
  [@ocaml.warning "-32"];
  module Raw = {
    type t_l2;
    type t_l3;
    type t_l4;
    type t = {
      l1: ListFragment.Raw.t,
      l2: t_l2,
      l3: t_l3,
      l4: t_l4,
      l5: FragmentWithArgs.Raw.t,
    };
    type t_variables = {arg1: Js.Nullable.t(string)};
  };
  type t_l2 = {
    frag1: ListFragment.t_Lists,
    frag2: ListFragment.t_Lists,
  };
  type t_l3 = {
    nullableOfNullable: option(array(option(string))),
    frag1: ListFragment.t_Lists,
    frag2: ListFragment.t_Lists,
  };
  type t_l4 = {
    nullableOfNullable: option(array(option(string))),
    inlineListFragment: InlineListFragment.t_Lists,
  };
  type t = {
    l1: ListFragment.t,
    l2: t_l2,
    l3: t_l3,
    l4: t_l4,
    l5: FragmentWithArgs.t,
  };
  /**The GraphQL query string*/
  let query: string =
    [%raw
      "(frag_0, frag_1, frag_2) => require(\"gql\")`\n  query MyQuery($arg1: String)  {\n    l1: lists  {\n      ...ListFragment\n    }\n    l2: lists  {\n      ...ListFragment\n      ...ListFragment\n    }\n    l3: lists  {\n      nullableOfNullable\n      ...ListFragment\n      ...ListFragment\n    }\n    l4: lists  {\n      nullableOfNullable\n      ...InlineListFragment\n    }\n    l5: lists  {\n      ...FragmentWithArgs\n    }\n  }\n  ${frag_0}\n  ${frag_1}\n  ${frag_2}\n`"
    ](
      FragmentWithArgs.query,
      InlineListFragment.query,
      ListFragment.query,
    );
  type t_variables = {arg1: option(string)};
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => (
    {
      l1: {
        let value = (value: Raw.t).l1;

        ListFragment.verifyArgsAndParse(~fragmentName=`ListFragment, value);
      },
      l2: {
        let value = (value: Raw.t).l2;
        (
          {
            frag1: {
              let value: ListFragment.Raw.t = Obj.magic(value);

              ListFragment.verifyArgsAndParse(
                ~fragmentName=`ListFragment,
                value,
              );
            },
            frag2: {
              let value: ListFragment.Raw.t = Obj.magic(value);

              ListFragment.verifyArgsAndParse(
                ~fragmentName=`ListFragment,
                value,
              );
            },
          }: t_l2
        );
      },
      l3: {
        let value = (value: Raw.t).l3;
        (
          {
            nullableOfNullable: {
              let value =
                Obj.magic(
                  Js.Dict.unsafeGet(Obj.magic(value), "nullableOfNullable"),
                );
              switch (Js.toOption(value)) {
              | Some(value) =>
                Some(
                  value
                  |> Js.Array.map(value =>
                       switch (Js.toOption(value)) {
                       | Some(value) => Some(value)
                       | None => None
                       }
                     ),
                )
              | None => None
              };
            },
            frag1: {
              let value: ListFragment.Raw.t = Obj.magic(value);

              ListFragment.verifyArgsAndParse(
                ~fragmentName=`ListFragment,
                value,
              );
            },
            frag2: {
              let value: ListFragment.Raw.t = Obj.magic(value);

              ListFragment.verifyArgsAndParse(
                ~fragmentName=`ListFragment,
                value,
              );
            },
          }: t_l3
        );
      },
      l4: {
        let value = (value: Raw.t).l4;
        (
          {
            nullableOfNullable: {
              let value =
                Obj.magic(
                  Js.Dict.unsafeGet(Obj.magic(value), "nullableOfNullable"),
                );
              switch (Js.toOption(value)) {
              | Some(value) =>
                Some(
                  value
                  |> Js.Array.map(value =>
                       switch (Js.toOption(value)) {
                       | Some(value) => Some(value)
                       | None => None
                       }
                     ),
                )
              | None => None
              };
            },
            inlineListFragment: {
              let value: InlineListFragment.Raw.t = Obj.magic(value);

              InlineListFragment.verifyArgsAndParse(
                ~fragmentName=`InlineListFragment,
                value,
              );
            },
          }: t_l4
        );
      },
      l5: {
        let value = (value: Raw.t).l5;

        FragmentWithArgs.verifyArgsAndParse(
          ~arg1=`String,
          ~fragmentName=`FragmentWithArgs,
          value,
        );
      },
    }: t
  );
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => (
    {
      let l5 = {
        let value = (value: t).l5;
        FragmentWithArgs.serialize(value);
      }
      and l4 = {
        let value = (value: t).l4;
        (
          Obj.magic(
            Js.Array.reduce(
              GraphQL_PPX.deepMerge,
              Obj.magic(
                {
                  let nullableOfNullable = {
                    let value = (value: t_l4).nullableOfNullable;
                    switch (value) {
                    | Some(value) =>
                      Js.Nullable.return(
                        value
                        |> Js.Array.map(value =>
                             switch (value) {
                             | Some(value) => Js.Nullable.return(value)
                             | None => Js.Nullable.null
                             }
                           ),
                      )
                    | None => Js.Nullable.null
                    };
                  };
                  {"nullableOfNullable": nullableOfNullable};
                },
              ): Js.Json.t,
              [|
                (
                  Obj.magic(
                    InlineListFragment.serialize(
                      (value: t_l4).inlineListFragment,
                    ),
                  ): Js.Json.t
                ),
              |],
            ),
          ): Raw.t_l4
        );
      }
      and l3 = {
        let value = (value: t).l3;
        (
          Obj.magic(
            Js.Array.reduce(
              GraphQL_PPX.deepMerge,
              Obj.magic(
                {
                  let nullableOfNullable = {
                    let value = (value: t_l3).nullableOfNullable;
                    switch (value) {
                    | Some(value) =>
                      Js.Nullable.return(
                        value
                        |> Js.Array.map(value =>
                             switch (value) {
                             | Some(value) => Js.Nullable.return(value)
                             | None => Js.Nullable.null
                             }
                           ),
                      )
                    | None => Js.Nullable.null
                    };
                  };
                  {"nullableOfNullable": nullableOfNullable};
                },
              ): Js.Json.t,
              [|
                (
                  Obj.magic(ListFragment.serialize((value: t_l3).frag1)): Js.Json.t
                ),
                (
                  Obj.magic(ListFragment.serialize((value: t_l3).frag2)): Js.Json.t
                ),
              |],
            ),
          ): Raw.t_l3
        );
      }
      and l2 = {
        let value = (value: t).l2;
        (
          Obj.magic(
            Js.Array.reduce(
              GraphQL_PPX.deepMerge,
              Obj.magic(Js.Dict.empty): Js.Json.t,
              [|
                (
                  Obj.magic(ListFragment.serialize((value: t_l2).frag1)): Js.Json.t
                ),
                (
                  Obj.magic(ListFragment.serialize((value: t_l2).frag2)): Js.Json.t
                ),
              |],
            ),
          ): Raw.t_l2
        );
      }
      and l1 = {
        let value = (value: t).l1;
        ListFragment.serialize(value);
      };
      {l1, l2, l3, l4, l5};
    }: Raw.t
  );
  let serializeVariables: t_variables => Raw.t_variables =
    inp => {
      arg1:
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) => Js.Nullable.return((a => a)(b))
            }
        )(
          (inp: t_variables).arg1,
        ),
    };
  let makeVariables = (~arg1=?, ()) =>
    serializeVariables({arg1: arg1}: t_variables);
  let makeDefaultVariables = () => makeVariables();
  external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
  external toJson: Raw.t => Js.Json.t = "%identity";
  external variablesToJson: Raw.t_variables => Js.Json.t = "%identity";
  module Z__INTERNAL = {
    type root = t;
    type nonrec graphql_module;
    /****--- graphql-ppx module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module GraphQL {
  /**
  The GraphQL query string
  */
  let query: string;

  /**
  This is the main type of the result you will get back.
  You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  */
  type t;

  /**
  Parse the JSON GraphQL data to ReasonML data types
  */
  let parse: Raw.t => t;

  /**
  Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data
  */
  let serialize: t => Raw.t;

  /**
  This is the JSON compatible type of the GraphQL data.
  It should not be necessary to access the types inside for normal use cases.
  */
  module Raw: { type t; };
}
```*/
    let graphql_module: graphql_module = Obj.magic(0);
  };
};
module MyQuery2 = {
  [@ocaml.warning "-32"];
  module Raw = {
    type t = {lists: ListFragment.Raw.t};
    type t_variables = unit;
  };
  type t = {lists: ListFragment.t};
  /**The GraphQL query string*/
  let query: string =
    [%raw
      "(frag_0) => require(\"gql\")`\n  query   {\n    lists  {\n      ...ListFragment\n    }\n  }\n  ${frag_0}\n`"
    ](
      ListFragment.query,
    );
  type t_variables = unit;
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => (
    {
      lists: {
        let value = (value: Raw.t).lists;

        ListFragment.verifyArgsAndParse(~fragmentName=`ListFragment, value);
      },
    }: t
  );
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => (
    {
      let lists = {
        let value = (value: t).lists;
        ListFragment.serialize(value);
      };
      {lists: lists};
    }: Raw.t
  );
  let serializeVariables = () => ();
  let makeVariables = () => ();
  let makeDefaultVariables = () => makeVariables();
  external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
  external toJson: Raw.t => Js.Json.t = "%identity";
  external variablesToJson: Raw.t_variables => Js.Json.t = "%identity";
  module Z__INTERNAL = {
    type root = t;
    type nonrec graphql_module;
    /****--- graphql-ppx module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module MyQuery2 {
  /**
  The GraphQL query string
  */
  let query: string;

  /**
  This is the main type of the result you will get back.
  You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  */
  type t;

  /**
  Parse the JSON GraphQL data to ReasonML data types
  */
  let parse: Raw.t => t;

  /**
  Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data
  */
  let serialize: t => Raw.t;

  /**
  This is the JSON compatible type of the GraphQL data.
  It should not be necessary to access the types inside for normal use cases.
  */
  module Raw: { type t; };
}
```*/
    let graphql_module: graphql_module = Obj.magic(0);
  };
};
