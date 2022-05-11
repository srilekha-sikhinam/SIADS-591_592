warning: LF will be replaced by CRLF in drought_crop.ipynb.
The file will have its original line endings in your working directory
[1mdiff --git a/drought_crop.ipynb b/drought_crop.ipynb[m
[1mindex 76e4eb0..d0fdd1d 100644[m
[1m--- a/drought_crop.ipynb[m
[1m+++ b/drought_crop.ipynb[m
[36m@@ -45,7 +45,10 @@[m
     "import altair as alt\n",[m
     "warnings.simplefilter(\"ignore\")\n",[m
     "%matplotlib inline\n",[m
[31m-    "import ee"[m
[32m+[m[32m    "import ee\n",[m
[32m+[m[32m    "\n",[m
[32m+[m[32m    "# set max df column display\n",[m
[32m+[m[32m    "pd.set_option('display.max_columns', 500)"[m
    ][m
   },[m
   {[m
[36m@@ -222,19 +225,19 @@[m
   },[m
   {[m
    "cell_type": "code",[m
[31m-   "execution_count": 4,[m
[32m+[m[32m   "execution_count": 19,[m
    "metadata": {},[m
    "outputs": [],[m
    "source": [[m
     "# get all the data together\n",[m
[31m-    "def getframe():\n",[m
[31m-    "    path = 'crops_datasets_raw'\n",[m
[32m+[m[32m    "def getframe(folderpath, axis=0):\n",[m
[32m+[m[32m    "    path = folderpath\n",[m
     "    all_files = glob.glob(os.path.join(path, \"*.csv\"))\n",[m
     "    df_from_each_file = (pd.read_csv(f) for f in all_files)\n",[m
[31m-    "    concat_df   = pd.concat(df_from_each_file, ignore_index=True)\n",[m
[32m+[m[32m    "    concat_df   = pd.concat(df_from_each_file, axis=axis, ignore_index=True)\n",[m
     "    return concat_df\n",[m
     "\n",[m
[31m-    "crop_df = getframe()"[m
[32m+[m[32m    "crop_df = getframe('crops_datasets_raw')"[m
    ][m
   },[m
   {[m
[36m@@ -273,7 +276,7 @@[m
        "      <th>Ag District</th>\n",[m
        "      <th>Ag District Code</th>\n",[m
        "      <th>County</th>\n",[m
[31m-       "      <th>...</th>\n",[m
[32m+[m[32m       "      <th>County ANSI</th>\n",[m
        "      <th>Zip Code</th>\n",[m
        "      <th>Region</th>\n",[m
        "      <th>watershed_code</th>\n",[m
[36m@@ -299,7 +302,7 @@[m
        "      <td>NaN</td>\n",[m
        "      <td>NaN</td>\n",[m
        "      <td>NaN</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[32m+[m[32m       "      <td>NaN</td>\n",[m
        "      <td>NaN</td>\n",[m
        "      <td>NaN</td>\n",[m
        "      <td>0</td>\n",[m
[36m@@ -323,7 +326,7 @@[m
        "      <td>NaN</td>\n",[m
        "      <td>NaN</td>\n",[m
        "      <td>NaN</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[32m+[m[32m       "      <td>NaN</td>\n",[m
        "      <td>NaN</td>\n",[m
        "      <td>NaN</td>\n",[m
        "      <td>0</td>\n",[m
[36m@@ -347,7 +350,7 @@[m
        "      <td>NaN</td>\n",[m
        "      <td>NaN</td>\n",[m
        "      <td>NaN</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[32m+[m[32m       "      <td>NaN</td>\n",[m
        "      <td>NaN</td>\n",[m
        "      <td>NaN</td>\n",[m
        "      <td>0</td>\n",[m
[36m@@ -359,270 +362,35 @@[m
        "      <td>(NA)</td>\n",[m
        "      <td>NaN</td>\n",[m
        "    </tr>\n",[m
[31m-       "    <tr>\n",[m
[31m-       "      <th>3</th>\n",[m
[31m-       "      <td>SURVEY</td>\n",[m
[31m-       "      <td>2020</td>\n",[m
[31m-       "      <td>MARKETING YEAR</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>STATE</td>\n",[m
[31m-       "      <td>ALABAMA</td>\n",[m
[31m-       "      <td>1</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>0</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>COTTON</td>\n",[m
[31m-       "      <td>COTTON, UPLAND - PRICE RECEIVED, MEASURED IN $...</td>\n",[m
[31m-       "      <td>TOTAL</td>\n",[m
[31m-       "      <td>NOT SPECIFIED</td>\n",[m
[31m-       "      <td>0.684</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "    </tr>\n",[m
[31m-       "    <tr>\n",[m
[31m-       "      <th>4</th>\n",[m
[31m-       "      <td>SURVEY</td>\n",[m
[31m-       "      <td>2020</td>\n",[m
[31m-       "      <td>MARKETING YEAR</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>STATE</td>\n",[m
[31m-       "      <td>ALABAMA</td>\n",[m
[31m-       "      <td>1</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>0</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>HAY</td>\n",[m
[31m-       "      <td>HAY - PRICE RECEIVED, MEASURED IN $ / TON</td>\n",[m
[31m-       "      <td>TOTAL</td>\n",[m
[31m-       "      <td>NOT SPECIFIED</td>\n",[m
[31m-       "      <td>96</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "    </tr>\n",[m
[31m-       "    <tr>\n",[m
[31m-       "      <th>...</th>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "    </tr>\n",[m
[31m-       "    <tr>\n",[m
[31m-       "      <th>295831</th>\n",[m
[31m-       "      <td>SURVEY</td>\n",[m
[31m-       "      <td>2010</td>\n",[m
[31m-       "      <td>DEC</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>STATE</td>\n",[m
[31m-       "      <td>WYOMING</td>\n",[m
[31m-       "      <td>56</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>0</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>BARLEY</td>\n",[m
[31m-       "      <td>BARLEY, MALTING - PRICE RECEIVED, MEASURED IN ...</td>\n",[m
[31m-       "      <td>TOTAL</td>\n",[m
[31m-       "      <td>NOT SPECIFIED</td>\n",[m
[31m-       "      <td>(D)</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "    </tr>\n",[m
[31m-       "    <tr>\n",[m
[31m-       "      <th>295832</th>\n",[m
[31m-       "      <td>SURVEY</td>\n",[m
[31m-       "      <td>2010</td>\n",[m
[31m-       "      <td>DEC</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>STATE</td>\n",[m
[31m-       "      <td>WYOMING</td>\n",[m
[31m-       "      <td>56</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>0</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>HAY</td>\n",[m
[31m-       "      <td>HAY - PRICE RECEIVED, MEASURED IN $ / TON</td>\n",[m
[31m-       "      <td>TOTAL</td>\n",[m
[31m-       "      <td>NOT SPECIFIED</td>\n",[m
[31m-       "      <td>89</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "    </tr>\n",[m
[31m-       "    <tr>\n",[m
[31m-       "      <th>295833</th>\n",[m
[31m-       "      <td>SURVEY</td>\n",[m
[31m-       "      <td>2010</td>\n",[m
[31m-       "      <td>DEC</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>STATE</td>\n",[m
[31m-       "      <td>WYOMING</td>\n",[m
[31m-       "      <td>56</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>0</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>HAY</td>\n",[m
[31m-       "      <td>HAY - SALES, MEASURED IN PCT OF MKTG YEAR</td>\n",[m
[31m-       "      <td>TOTAL</td>\n",[m
[31m-       "      <td>NOT SPECIFIED</td>\n",[m
[31m-       "      <td>7</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "    </tr>\n",[m
[31m-       "    <tr>\n",[m
[31m-       "      <th>295834</th>\n",[m
[31m-       "      <td>SURVEY</td>\n",[m
[31m-       "      <td>2010</td>\n",[m
[31m-       "      <td>DEC</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>STATE</td>\n",[m
[31m-       "      <td>WYOMING</td>\n",[m
[31m-       "      <td>56</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>0</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>HAY</td>\n",[m
[31m-       "      <td>HAY, (EXCL ALFALFA) - PRICE RECEIVED, MEASURED...</td>\n",[m
[31m-       "      <td>TOTAL</td>\n",[m
[31m-       "      <td>NOT SPECIFIED</td>\n",[m
[31m-       "      <td>85</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "    </tr>\n",[m
[31m-       "    <tr>\n",[m
[31m-       "      <th>295835</th>\n",[m
[31m-       "      <td>SURVEY</td>\n",[m
[31m-       "      <td>2010</td>\n",[m
[31m-       "      <td>DEC</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>STATE</td>\n",[m
[31m-       "      <td>WYOMING</td>\n",[m
[31m-       "      <td>56</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>...</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>0</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "      <td>HAY</td>\n",[m
[31m-       "      <td>HAY, ALFALFA - PRICE RECEIVED, MEASURED IN $ /...</td>\n",[m
[31m-       "      <td>TOTAL</td>\n",[m
[31m-       "      <td>NOT SPECIFIED</td>\n",[m
[31m-       "      <td>90</td>\n",[m
[31m-       "      <td>NaN</td>\n",[m
[31m-       "    </tr>\n",[m
        "  </tbody>\n",[m
        "</table>\n",[m
[31m-       "<p>295836 rows × 21 columns</p>\n",[m
        "</div>"[m
       ],[m
       "text/plain": [[m
[31m-       "       Program  Year          Period  Week Ending Geo Level    State  \\\n",[m
[31m-       "0       SURVEY  2020  MARKETING YEAR          NaN     STATE  ALABAMA   \n",[m
[31m-       "1       SURVEY  2020  MARKETING YEAR          NaN     STATE  ALABAMA   \n",[m
[31m-       "2       SURVEY  2020  MARKETING YEAR          NaN     STATE  ALABAMA   \n",[m
[31m-       "3       SURVEY  2020  MARKETING YEAR          NaN     STATE  ALABAMA   \n",[m
[31m-       "4       SURVEY  2020  MARKETING YEAR          NaN     STATE  ALABAMA   \n",[m
[31m-       "...        ...   ...             ...          ...       ...      ...   \n",[m
[31m-       "295831  SURVEY  2010             DEC          NaN     STATE  WYOMING   \n",[m
[31m-       "295832  SURVEY  2010             DEC          NaN     STATE  WYOMING   \n",[m
[31m-       "295833  SURVEY  2010             DEC          NaN     STATE  WYOMING   \n",[m
[31m-       "295834  SURVEY  2010             DEC          NaN     STATE  WYOMING   \n",[m
[31m-       "295835  SURVEY  2010             DEC          NaN     STATE  WYOMING   \n",[m
[31m-       "\n",[m
[31m-       "        State ANSI  Ag District  Ag District Code  County  ...  Zip Code  \\\n",[m
[31m-       "0                1          NaN               NaN     NaN  ...       NaN   \n",[m
[31m-       "1                1          NaN               NaN     NaN  ...       NaN   \n",[m
[31m-       "2                1          NaN               NaN     NaN  ...       NaN   \n",[m
[31m-       "3                1          NaN               NaN     NaN  ...       NaN   \n",[m
[31m-       "4                1          NaN               NaN     NaN  ...       NaN   \n",[m
[31m-       "...            ...          ...               ...     ...  ...       ...   \n",[m
[31m-       "295831          56          NaN               NaN     NaN  ...       NaN   \n",[m
[31m-       "295832          56          NaN               NaN     NaN  ...       NaN   \n",[m
[31m-       "295833          56          NaN               NaN     NaN  ...       NaN   \n",[m
[31m-       "295834          56          NaN               NaN     NaN  ...       NaN   \n",[m
[31m-       "295835          56          NaN               NaN     NaN  ...       NaN   \n",[m
[32m+[m[32m       "  Program  Year          Period  Week Ending Geo Level    State  State ANSI  \\\n",[m
[32m+[m[32m       "0  SURVEY  2020  MARKETING YEAR          NaN     STATE  ALABAMA           1   \n",[m
[32m+[m[32m       "1  SURVEY  2020  MARKETING YEAR          NaN     STATE  ALABAMA           1   \n",[m
[32m+[m[32m       "2  SURVEY  2020  MARKETING YEAR          NaN     STATE  ALABAMA           1   \n",[m
        "\n",[m
[31m-       "        Region  watershed_code  Watershed  Commodity  \\\n",[m
[31m-       "0          NaN               0        NaN       CORN   \n",[m
[31m-       "1          NaN               0        NaN     COTTON   \n",[m
[31m-       "2          NaN               0        NaN     COTTON   \n",[m
[31m-       "3          NaN               0        NaN     COTTON   \n",[m
[31m-       "4          NaN               0        NaN        HAY   \n",[m
[31m-       "...        ...             ...        ...        ...   \n",[m
[31m-       "295831     NaN               0        NaN     BARLEY   \n",[m
[31m-       "295832     NaN               0        NaN        HAY   \n",[m
[31m-       "295833     NaN               0        NaN        HAY   \n",[m
[31m-       "295834     NaN               0        NaN        HAY   \n",[m
[31m-       "295835     NaN               0        NaN        HAY   \n",[m
[32m+[m[32m       "   Ag District  Ag District Code  County  County ANSI  Zip Code  Region  \\\n",[m
[32m+[m[32m       "0          NaN               NaN     NaN          NaN       NaN     NaN   \n",[m
[32m+[m[32m       "1          NaN               NaN     NaN          NaN       NaN     NaN   \n",[m
[32m+[m[32m       "2          NaN               NaN     NaN          NaN       NaN     NaN   \n",[m
        "\n",[m
[31m-       "                                                Data Item Domain  \\\n",[m
[31m-       "0        CORN, GRAIN - PRICE RECEIVED, MEASURED IN $ / BU  TOTAL   \n",[m
[31m-       "1       COTTON, COTTONSEED - PRICE RECEIVED, MEASURED ...  TOTAL   \n",[m
[31m-       "2       COTTON, PIMA - PRICE RECEIVED, MEASURED IN $ / LB  TOTAL   \n",[m
[31m-       "3       COTTON, UPLAND - PRICE RECEIVED, MEASURED IN $...  TOTAL   \n",[m
[31m-       "4               HAY - PRICE RECEIVED, MEASURED IN $ / TON  TOTAL   \n",[m
[31m-       "...                                                   ...    ...   \n",[m
[31m-       "295831  BARLEY, MALTING - PRICE RECEIVED, MEASURED IN ...  TOTAL   \n",[m
[31m-       "295832          HAY - PRICE RECEIVED, MEASURED IN $ / TON  TOTAL   \n",[m
[31m-       "295833          HAY - SALES, MEASURED IN PCT OF MKTG YEAR  TOTAL   \n",[m
[31m-       "295834  HAY, (EXCL ALFALFA) - PRICE RECEIVED, MEASURED...  TOTAL   \n",[m
[31m-       "295835  HAY, ALFALFA - PRICE RECEIVED, MEASURED IN $ /...  TOTAL   \n",[m
[32m+[m[32m       "   watershed_code  Watershed Commodity  \\\n",[m
[32m+[m