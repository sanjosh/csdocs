
https://jakevdp.github.io/PythonDataScienceHandbook/index.html

## basic

df.name

df.nunique or df."column_name".unique

df.replace

df.apply(pd.to_numeric) // convert columns to numeric

df.dropna

df.keys

df.select_dtypes

df.info

df.shape

df.dtypes

df.values

## Purging NaN and Inf

df.isna

df.fillna

df.isnf

df.interpolate


## stats

df.corr

pct_change

pd.crosstab

df.describe

df.corrwith(another df)

## rename

df.rename

df2.columns = ['A', 'B']  

## compare or merge dataframes

df.combine

df.align

df.interpolate

df.merge(how = '')

df1['ColumnName'].isin(df2['ColumnName']).value_counts()

df1.where(df1.values==df2.values).notna()

set(df1['c2']).intersection(set(df2['c2']))

## split x y

y = df['label']
X = df.drop('label',axis=1)

y = df['label']
X = df.loc[:, df.columns != 'label']

## extract columns and rename

df = df[["c1", "c2"]]
df.columns = ["c1", any_name]

## index

df['Datetime'] = pd.to_datetime(df['date'] + ' ' + df['time'])
df = df.set_index('Datetime')
https://stackoverflow.com/questions/27032052/how-do-i-properly-set-the-datetimeindex-for-a-pandas-datetime-object-in-a-datafr

## plotting

https://stackoverflow.com/questions/37414008/plotting-multiple-dataframes-using-pandas-functionality


